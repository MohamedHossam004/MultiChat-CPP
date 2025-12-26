#ifndef SHMHANDLER_H
#define SHMHANDLER_H

#include <QObject>
#include <QSharedMemory>
#include <QSystemSemaphore>
#include <QTimer>
#include <QDateTime>
#include "common.h"

class ShmHandler : public QObject
{
    Q_OBJECT
public:
    explicit ShmHandler(QObject *parent = nullptr);
    ~ShmHandler();

    void initReceiver();
    void sendMessage(const QString &sender, const QString &text, int priority);

public slots:
    void setAlgorithm(int index); // 0:FCFS, 1:Priority, 2:RR, 3:SJF
    void setLocalName(const QString &name); // NEW: Identify "myself"

signals:
    void logMessage(const QString &text);
    void messageReceived(const QString &sender, const QString &text);

private slots:
    void processSharedMemory();

private:
    QSharedMemory sharedMemory;
    QSystemSemaphore *semSlots;
    QSystemSemaphore *semItems;
    QTimer *timer;

    int currentAlgorithm = 0;
    int rr_last = 0;
    QString m_localName; // NEW: Stores current user's name

    void remove_at(SharedBuffer* b, int idx);
    bool ensureMemoryReady();
};

#endif // SHMHANDLER_H
