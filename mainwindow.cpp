#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

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
    QString dir = ui->directoryEdit->text().trimmed();
    if (dir.isEmpty()) {
        QMessageBox::information(this, "Информация", "Введите путь к директории для добавления.");
        return;
    }

    monitor->addDirectory(dir);
    updateDirectoryList();
    ui->directoryEdit->clear();
}

void MainWindow::removeDirectory()
{
    QString dir = ui->directoryEdit->text().trimmed();
    if (dir.isEmpty()) {
        QMessageBox::information(this, "Информация", "Введите путь к директории для удаления.");
        return;
    }

    monitor->removeDirectory(dir);
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
    ui->directoryList->addItems(monitor->monitoredDirectories());
}
