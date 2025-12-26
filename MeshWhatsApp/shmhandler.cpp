#include "shmhandler.h"

ShmHandler::ShmHandler(QObject *parent)
    : QObject(parent), sharedMemory(SHM_KEY)
{
    semSlots = new QSystemSemaphore(SEM_SLOTS_KEY, MAX_MESSAGES, QSystemSemaphore::Create);
    semItems = new QSystemSemaphore(SEM_ITEMS_KEY, 0, QSystemSemaphore::Create);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ShmHandler::processSharedMemory);
}

ShmHandler::~ShmHandler() {
    delete semSlots;
    delete semItems;
}

void ShmHandler::setAlgorithm(int index) {
    currentAlgorithm = index;
}

void ShmHandler::setLocalName(const QString &name) {
    m_localName = name;
}

bool ShmHandler::ensureMemoryReady() {
    if (!sharedMemory.isAttached() && !sharedMemory.attach()) {
        if (!sharedMemory.create(sizeof(SharedBuffer))) return false;

        sharedMemory.lock();
        SharedBuffer *buf = (SharedBuffer*)sharedMemory.data();
        if(buf) buf->count = 0;
        sharedMemory.unlock();
    }
    return true;
}

void ShmHandler::initReceiver() {
    if (ensureMemoryReady()) {
        emit logMessage("<b style='color:blue;'>[SHM] Receiver Initialized & Monitoring...</b>");
        timer->start(100);
    } else {
        emit logMessage("<b style='color:red;'>Error: Could not attach SHM.</b>");
    }
}

void ShmHandler::sendMessage(const QString &sender, const QString &text, int priority) {
    if (!ensureMemoryReady()) {
        emit logMessage("Error: SHM not ready. Click Init Receiver first.");
        return;
    }

    if (sharedMemory.lock()) {
        SharedBuffer *buf = (SharedBuffer*)sharedMemory.data();
        if (buf->count < MAX_MESSAGES) {
            ChatMessage &m = buf->messages[buf->count];

            strncpy(m.sender, sender.toUtf8().constData(), 31);
            m.sender[31] = '\0';

            strncpy(m.text, text.toUtf8().constData(), TEXT_SIZE - 1);
            m.text[TEXT_SIZE - 1] = '\0';

            QByteArray timeBytes = QDateTime::currentDateTime().toString("hh:mm:ss").toUtf8();
            strncpy(m.timestamp, timeBytes.constData(), 31);
            m.timestamp[31] = '\0';

            m.priority = priority;
            buf->count++;

            emit logMessage("<i>Sent to Shared Memory...</i>");
        } else {
            emit logMessage("<b style='color:red;'>Buffer Full!</b>");
        }
        sharedMemory.unlock();
    }
}

void ShmHandler::remove_at(SharedBuffer* b, int idx) {
    for (int i = idx; i + 1 < b->count; ++i)
        b->messages[i] = b->messages[i + 1];
    b->count--;
}

void ShmHandler::processSharedMemory() {
    if (!sharedMemory.isAttached()) return;

    if (sharedMemory.lock()) {
        SharedBuffer *buf = (SharedBuffer*)sharedMemory.data();

        if (buf && buf->count > 0) {
            int index = -1; // -1 means "no valid message found for me"

            // ALGORITHM LOGIC:
            // We iterate through messages. We only pick a message if
            // sender != m_localName.

            if (currentAlgorithm == 0) { // FCFS
                for (int i = 0; i < buf->count; i++) {
                    if (QString(buf->messages[i].sender) != m_localName) {
                        index = i;
                        break; // Take the first one that isn't mine
                    }
                }
            }
            else if (currentAlgorithm == 1) { // Priority
                int best = -1;
                for (int i = 0; i < buf->count; i++) {
                    if (QString(buf->messages[i].sender) == m_localName) continue; // Skip mine

                    if (best == -1 || buf->messages[i].priority < buf->messages[best].priority) {
                        best = i;
                    }
                }
                index = best;
            }
            else if (currentAlgorithm == 2) { // Round Robin
                for (int i = 0; i < buf->count; i++) {
                    int curr = (rr_last + i) % buf->count;
                    if (QString(buf->messages[curr].sender) != m_localName) {
                        index = curr;
                        rr_last = curr + 1; // Advance RR pointer
                        break;
                    }
                }
            }
            else if (currentAlgorithm == 3) { // SJF
                int best = -1;
                for (int i = 0; i < buf->count; i++) {
                    if (QString(buf->messages[i].sender) == m_localName) continue; // Skip mine

                    if (best == -1 || strlen(buf->messages[i].text) < strlen(buf->messages[best].text)) {
                        best = i;
                    }
                }
                index = best;
            }

            // If we found a message meant for us (index != -1), consume it.
            if (index != -1) {
                ChatMessage msg = buf->messages[index];
                remove_at(buf, index);
                emit messageReceived(QString(msg.sender), QString(msg.text));
            }
        }
        sharedMemory.unlock();
    }
}
