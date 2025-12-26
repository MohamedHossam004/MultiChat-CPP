#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1. Initialize Handlers
    m_socketHandler = new SocketHandler(this);
    m_shmHandler = new ShmHandler(this);

    // 2. Connect Socket Signals
    connect(m_socketHandler, &SocketHandler::connected, this, &MainWindow::onSocketConnected);
    connect(m_socketHandler, &SocketHandler::disconnected, this, &MainWindow::onSocketDisconnected);
    connect(m_socketHandler, &SocketHandler::newMessageReceived, this, &MainWindow::onSocketNewMessage);

    // 3. Connect SHM Signals
    connect(m_shmHandler, &ShmHandler::logMessage, this, &MainWindow::onShmLog);
    connect(m_shmHandler, &ShmHandler::messageReceived, this, &MainWindow::onShmMessageReceived);

    // 4. Connect Algorithm Selector
    connect(ui->algoComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_algoComboBox_currentIndexChanged);

    // Set initial algo
    m_shmHandler->setAlgorithm(ui->algoComboBox->currentIndex());
}

MainWindow::~MainWindow() {
    delete ui;
}

// =================================================================
// PART A: SOCKET UI
// =================================================================

void MainWindow::on_connectButton_clicked() {
    if (!m_socketHandler->isConnected()) {
        m_socketHandler->connectToServer(ui->ipInput->text(), ui->portInput->text().toInt());
    } else {
        m_socketHandler->disconnectFromServer();
    }
}

void MainWindow::onSocketConnected() {
    ui->chatDisplay->append(QString("<b style='color:green;'>[Socket] Connected to %1:%2</b>")
                                .arg(m_socketHandler->getPeerName(), m_socketHandler->getPeerPort()));
    ui->connectButton->setText("Disconnect");

    // Legacy support: send name on connect if needed
    m_socketHandler->sendMessage(ui->nameInput->text());
}

void MainWindow::onSocketDisconnected() {
    ui->chatDisplay->append("<b style='color:red;'>[Socket] Disconnected.</b>");
    ui->connectButton->setText("Connect");
}

void MainWindow::onSocketNewMessage(const QString &text) {
    ui->chatDisplay->append(text);
}

void MainWindow::on_sendSocketButton_clicked() {
    QString msg = ui->messageInput->text();
    if (!msg.isEmpty() && m_socketHandler->isConnected()) {
        m_socketHandler->sendMessage(msg);
        ui->chatDisplay->append("<b>You:</b> " + msg);
        ui->messageInput->clear();
    } else {
        ui->chatDisplay->append("<i style='color:red;'>System: Not connected to server.</i>");
    }
}

// =================================================================
// PART B: SHARED MEMORY UI
// =================================================================

void MainWindow::on_initShmButton_clicked() {
    // NEW: Tell handler who we are so we don't read our own msgs
    m_shmHandler->setLocalName(ui->nameInput->text());
    m_shmHandler->initReceiver();
}

void MainWindow::on_sendShmButton_clicked() {
    QString name = ui->nameInput->text();
    QString msg = ui->messageInput->text();
    int priority = ui->prioritySpinBox->value();

    if (name.isEmpty() || msg.isEmpty()) {
        ui->chatDisplay->append("<i style='color:red;'>Error: Name and Message required.</i>");
        return;
    }

    // NEW: Update name just in case it changed
    m_shmHandler->setLocalName(name);

    m_shmHandler->sendMessage(name, msg, priority);
    ui->messageInput->clear();
}

void MainWindow::on_algoComboBox_currentIndexChanged(int index) {
    m_shmHandler->setAlgorithm(index);
    ui->chatDisplay->append(QString("<i>Algorithm changed to index %1</i>").arg(index));
}

void MainWindow::onShmLog(const QString &text) {
    ui->chatDisplay->append(text);
}

void MainWindow::onShmMessageReceived(const QString &sender, const QString &text) {
    ui->chatDisplay->append(QString("<font color='blue'><b>[SHM] %1:</b> %2</font>")
                                .arg(sender, text));
}
