#include "sockethandler.h"

SocketHandler::SocketHandler(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, &SocketHandler::connected);
    connect(socket, &QTcpSocket::disconnected, this, &SocketHandler::disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &SocketHandler::onReadyRead);
}

void SocketHandler::connectToServer(const QString &ip, int port) {
    if (socket->state() != QAbstractSocket::ConnectedState)
        socket->connectToHost(ip, port);
}

void SocketHandler::disconnectFromServer() {
    socket->disconnectFromHost();
}

void SocketHandler::sendMessage(const QString &msg) {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        // Appending null terminator as per original logic
        socket->write(msg.toUtf8() + '\0');
    }
}

bool SocketHandler::isConnected() {
    return socket->state() == QAbstractSocket::ConnectedState;
}

QString SocketHandler::getPeerName() {
    return socket->peerName();
}

QString SocketHandler::getPeerPort() {
    return QString::number(socket->peerPort());
}

void SocketHandler::onReadyRead() {
    QByteArray data = socket->readAll();
    emit newMessageReceived(QString::fromUtf8(data));
}
