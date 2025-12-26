#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sockethandler.h"
#include "shmhandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // --- UI Interactions ---
    void on_connectButton_clicked();
    void on_sendSocketButton_clicked();
    void on_initShmButton_clicked();
    void on_sendShmButton_clicked();
    void on_algoComboBox_currentIndexChanged(int index);

    // --- Socket Signals ---
    void onSocketConnected();
    void onSocketDisconnected();
    void onSocketNewMessage(const QString &text);

    // --- SHM Signals ---
    void onShmLog(const QString &text);
    void onShmMessageReceived(const QString &sender, const QString &text);

private:
    Ui::MainWindow *ui;

    // Handlers
    SocketHandler *m_socketHandler;
    ShmHandler *m_shmHandler;
};
#endif // MAINWINDOW_H
