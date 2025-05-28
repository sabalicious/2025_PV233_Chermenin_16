/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayoutMain;
    QLabel *labelTitle;
    QGroupBox *groupBoxDirectories;
    QVBoxLayout *verticalLayoutDirectories;
    QHBoxLayout *horizontalLayoutDirInput;
    QLineEdit *directoryEdit;
    QVBoxLayout *verticalLayoutDirButtons;
    QPushButton *addButton;
    QPushButton *removeButton;
    QListWidget *directoryList;
    QGroupBox *groupBoxLogs;
    QVBoxLayout *verticalLayoutLogs;
    QHBoxLayout *horizontalLayoutLogFile;
    QLineEdit *logFileEdit;
    QVBoxLayout *verticalLayoutLogButtons;
    QPushButton *setLogButton;
    QPushButton *showLogButton;
    QTextEdit *logTextEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(650, 550);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutMain = new QVBoxLayout(centralwidget);
        verticalLayoutMain->setObjectName(QString::fromUtf8("verticalLayoutMain"));
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);
        labelTitle->setStyleSheet(QString::fromUtf8("color: #2A7AE2;"));

        verticalLayoutMain->addWidget(labelTitle);

        groupBoxDirectories = new QGroupBox(centralwidget);
        groupBoxDirectories->setObjectName(QString::fromUtf8("groupBoxDirectories"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        groupBoxDirectories->setFont(font1);
        verticalLayoutDirectories = new QVBoxLayout(groupBoxDirectories);
        verticalLayoutDirectories->setObjectName(QString::fromUtf8("verticalLayoutDirectories"));
        horizontalLayoutDirInput = new QHBoxLayout();
        horizontalLayoutDirInput->setObjectName(QString::fromUtf8("horizontalLayoutDirInput"));
        directoryEdit = new QLineEdit(groupBoxDirectories);
        directoryEdit->setObjectName(QString::fromUtf8("directoryEdit"));

        horizontalLayoutDirInput->addWidget(directoryEdit);

        verticalLayoutDirButtons = new QVBoxLayout();
        verticalLayoutDirButtons->setObjectName(QString::fromUtf8("verticalLayoutDirButtons"));
        addButton = new QPushButton(groupBoxDirectories);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; color: white; font-weight: bold;"));

        verticalLayoutDirButtons->addWidget(addButton);

        removeButton = new QPushButton(groupBoxDirectories);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setStyleSheet(QString::fromUtf8("background-color: #f44336; color: white; font-weight: bold;"));

        verticalLayoutDirButtons->addWidget(removeButton);


        horizontalLayoutDirInput->addLayout(verticalLayoutDirButtons);


        verticalLayoutDirectories->addLayout(horizontalLayoutDirInput);

        directoryList = new QListWidget(groupBoxDirectories);
        directoryList->setObjectName(QString::fromUtf8("directoryList"));

        verticalLayoutDirectories->addWidget(directoryList);


        verticalLayoutMain->addWidget(groupBoxDirectories);

        groupBoxLogs = new QGroupBox(centralwidget);
        groupBoxLogs->setObjectName(QString::fromUtf8("groupBoxLogs"));
        groupBoxLogs->setFont(font1);
        verticalLayoutLogs = new QVBoxLayout(groupBoxLogs);
        verticalLayoutLogs->setObjectName(QString::fromUtf8("verticalLayoutLogs"));
        horizontalLayoutLogFile = new QHBoxLayout();
        horizontalLayoutLogFile->setObjectName(QString::fromUtf8("horizontalLayoutLogFile"));
        logFileEdit = new QLineEdit(groupBoxLogs);
        logFileEdit->setObjectName(QString::fromUtf8("logFileEdit"));

        horizontalLayoutLogFile->addWidget(logFileEdit);

        verticalLayoutLogButtons = new QVBoxLayout();
        verticalLayoutLogButtons->setObjectName(QString::fromUtf8("verticalLayoutLogButtons"));
        setLogButton = new QPushButton(groupBoxLogs);
        setLogButton->setObjectName(QString::fromUtf8("setLogButton"));
        setLogButton->setStyleSheet(QString::fromUtf8("background-color: #2196F3; color: white; font-weight: bold;"));

        verticalLayoutLogButtons->addWidget(setLogButton);

        showLogButton = new QPushButton(groupBoxLogs);
        showLogButton->setObjectName(QString::fromUtf8("showLogButton"));
        showLogButton->setStyleSheet(QString::fromUtf8("background-color: #FF9800; color: white; font-weight: bold;"));

        verticalLayoutLogButtons->addWidget(showLogButton);


        horizontalLayoutLogFile->addLayout(verticalLayoutLogButtons);


        verticalLayoutLogs->addLayout(horizontalLayoutLogFile);

        logTextEdit = new QTextEdit(groupBoxLogs);
        logTextEdit->setObjectName(QString::fromUtf8("logTextEdit"));
        logTextEdit->setReadOnly(true);
        logTextEdit->setMinimumHeight(160);
        logTextEdit->setStyleSheet(QString::fromUtf8("background-color: #f0f0f0; font-family: Consolas; font-size: 11pt;"));

        verticalLayoutLogs->addWidget(logTextEdit);


        verticalLayoutMain->addWidget(groupBoxLogs);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\275\320\270\321\202\320\276\321\200 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\271", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\275\320\270\321\202\320\276\321\200\320\270\320\275\320\263 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\271 \320\262 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\217\321\205", nullptr));
        groupBoxDirectories->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\270 \320\264\320\273\321\217 \320\274\320\276\320\275\320\270\321\202\320\276\321\200\320\270\320\275\320\263\320\260", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        groupBoxLogs->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\273\320\276\320\263\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        setLogButton->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        showLogButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\273\320\276\320\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
