/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainVerticalLayout;
    QGroupBox *identityGroup;
    QHBoxLayout *identityLayout;
    QLineEdit *nameInput;
    QTabWidget *modeTabs;
    QWidget *socketTab;
    QVBoxLayout *socketLayout;
    QHBoxLayout *socketConfigLayout;
    QLineEdit *ipInput;
    QLineEdit *portInput;
    QPushButton *connectButton;
    QPushButton *sendSocketButton;
    QWidget *shmTab;
    QVBoxLayout *shmLayout;
    QHBoxLayout *shmConfigLayout;
    QComboBox *algoComboBox;
    QSpinBox *prioritySpinBox;
    QPushButton *initShmButton;
    QPushButton *sendShmButton;
    QTextBrowser *chatDisplay;
    QLineEdit *messageInput;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainVerticalLayout = new QVBoxLayout(centralwidget);
        mainVerticalLayout->setObjectName("mainVerticalLayout");
        identityGroup = new QGroupBox(centralwidget);
        identityGroup->setObjectName("identityGroup");
        identityLayout = new QHBoxLayout(identityGroup);
        identityLayout->setObjectName("identityLayout");
        nameInput = new QLineEdit(identityGroup);
        nameInput->setObjectName("nameInput");

        identityLayout->addWidget(nameInput);


        mainVerticalLayout->addWidget(identityGroup);

        modeTabs = new QTabWidget(centralwidget);
        modeTabs->setObjectName("modeTabs");
        socketTab = new QWidget();
        socketTab->setObjectName("socketTab");
        socketLayout = new QVBoxLayout(socketTab);
        socketLayout->setObjectName("socketLayout");
        socketConfigLayout = new QHBoxLayout();
        socketConfigLayout->setObjectName("socketConfigLayout");
        ipInput = new QLineEdit(socketTab);
        ipInput->setObjectName("ipInput");

        socketConfigLayout->addWidget(ipInput);

        portInput = new QLineEdit(socketTab);
        portInput->setObjectName("portInput");

        socketConfigLayout->addWidget(portInput);

        connectButton = new QPushButton(socketTab);
        connectButton->setObjectName("connectButton");

        socketConfigLayout->addWidget(connectButton);


        socketLayout->addLayout(socketConfigLayout);

        sendSocketButton = new QPushButton(socketTab);
        sendSocketButton->setObjectName("sendSocketButton");

        socketLayout->addWidget(sendSocketButton);

        modeTabs->addTab(socketTab, QString());
        shmTab = new QWidget();
        shmTab->setObjectName("shmTab");
        shmLayout = new QVBoxLayout(shmTab);
        shmLayout->setObjectName("shmLayout");
        shmConfigLayout = new QHBoxLayout();
        shmConfigLayout->setObjectName("shmConfigLayout");
        algoComboBox = new QComboBox(shmTab);
        algoComboBox->addItem(QString());
        algoComboBox->addItem(QString());
        algoComboBox->addItem(QString());
        algoComboBox->addItem(QString());
        algoComboBox->setObjectName("algoComboBox");

        shmConfigLayout->addWidget(algoComboBox);

        prioritySpinBox = new QSpinBox(shmTab);
        prioritySpinBox->setObjectName("prioritySpinBox");
        prioritySpinBox->setMinimum(1);
        prioritySpinBox->setMaximum(5);

        shmConfigLayout->addWidget(prioritySpinBox);

        initShmButton = new QPushButton(shmTab);
        initShmButton->setObjectName("initShmButton");

        shmConfigLayout->addWidget(initShmButton);


        shmLayout->addLayout(shmConfigLayout);

        sendShmButton = new QPushButton(shmTab);
        sendShmButton->setObjectName("sendShmButton");

        shmLayout->addWidget(sendShmButton);

        modeTabs->addTab(shmTab, QString());

        mainVerticalLayout->addWidget(modeTabs);

        chatDisplay = new QTextBrowser(centralwidget);
        chatDisplay->setObjectName("chatDisplay");

        mainVerticalLayout->addWidget(chatDisplay);

        messageInput = new QLineEdit(centralwidget);
        messageInput->setObjectName("messageInput");

        mainVerticalLayout->addWidget(messageInput);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        modeTabs->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        identityGroup->setTitle(QCoreApplication::translate("MainWindow", "User Identity", nullptr));
        nameInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Username...", nullptr));
        ipInput->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        portInput->setText(QCoreApplication::translate("MainWindow", "2005", nullptr));
        connectButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        sendSocketButton->setText(QCoreApplication::translate("MainWindow", "Send via Network", nullptr));
        modeTabs->setTabText(modeTabs->indexOf(socketTab), QCoreApplication::translate("MainWindow", "Socket Mode", nullptr));
        algoComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "FCFS", nullptr));
        algoComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Priority", nullptr));
        algoComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Round Robin", nullptr));
        algoComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "SJF", nullptr));

        initShmButton->setText(QCoreApplication::translate("MainWindow", "Initialize SHM", nullptr));
        sendShmButton->setText(QCoreApplication::translate("MainWindow", "Send to Shared Memory", nullptr));
        modeTabs->setTabText(modeTabs->indexOf(shmTab), QCoreApplication::translate("MainWindow", "Shared Memory", nullptr));
        messageInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Type message...", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
