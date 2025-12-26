#ifndef SOCKETHANDLER_H
#define SOCKETHANDLER_H

#include <QObject>
#include <QTcpSocket>

class SocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit SocketHandler(QObject *parent = nullptr);
    void connectToServer(const QString &ip, int port);
    void disconnectFromServer();
    void sendMessage(const QString &msg);
    bool isConnected();
    QString getPeerName();
    QString getPeerPort();

signals:
    void connected();
    void disconnected();
    void newMessageReceived(const QString &text);

private slots:
    void onReadyRead();

private:
    QTcpSocket *socket;
};

#endif // SOCKETHANDLER_H
