#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), monitor(new DirectoryMonitor(this))
{
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addDirectory);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::removeDirectory);
    connect(ui->setLogButton, &QPushButton::clicked, this, &MainWindow::setLogFile);
    connect(ui->showLogButton, &QPushButton::clicked, this, &MainWindow::showLogContents);

    connect(monitor.get(), &DirectoryMonitor::logUpdated, this, &MainWindow::updateLogDisplay);

    updateDirectoryList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addDirectory()
{
    QString path = ui->directoryEdit->text().trimmed();
    if (path.isEmpty()) {
        QMessageBox::information(this, "Информация", "Введите путь к файлу или директории для добавления.");
        return;
    }

    QFileInfo fileInfo(path);
    if (!fileInfo.exists()) {
        QMessageBox::warning(this, "Ошибка", "Указанный путь не существует.");
        return;
    }

    if (monitor->addPath(path)) {
        updateDirectoryList();
        ui->directoryEdit->clear();
        ui->statusbar->showMessage(QString("Добавлен для мониторинга: %1").arg(path), 3000);
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось добавить путь для мониторинга.");
    }
}

void MainWindow::removeDirectory()
{
    QString path = ui->directoryEdit->text().trimmed();
    if (path.isEmpty()) {
        QMessageBox::information(this, "Информация", "Введите путь к файлу или директории для удаления.");
        return;
    }

    monitor->removePath(path);
    updateDirectoryList();
    ui->directoryEdit->clear();
}

void MainWindow::setLogFile()
{
    QString file = ui->logFileEdit->text().trimmed();
    if (file.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Путь к файлу лога не может быть пустым.");
        return;
    }

    monitor->setLogFile(file);
    ui->statusbar->showMessage(QString("Файл лога установлен: %1").arg(file), 3000);
}

void MainWindow::showLogContents()
{
    if (monitor->getLogFilePath().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Файл лога не установлен.");
        return;
    }

    updateLogDisplay();
}

void MainWindow::updateLogDisplay()
{
    QString logFile = monitor->getLogFilePath();
    if (logFile.isEmpty()) {
        ui->logTextEdit->clear();
        return;
    }

    smart_ptr<QFile> file(new QFile(logFile));
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл лога.");
        return;
    }

    QTextStream in(file.get());
    ui->logTextEdit->setPlainText(in.readAll());
}

void MainWindow::updateDirectoryList()
{
    ui->directoryList->clear();
    ui->directoryList->addItems(monitor->monitoredPaths());
}
