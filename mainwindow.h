#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DirectoryMonitor.h"
#include "SmartPtr.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);  // Конструктор главного окна
    ~MainWindow() override;                          // Деструктор с override для безопасности

private slots:
    void addDirectory();      // Добавляет директорию для мониторинга
    void removeDirectory();   // Убирает директорию из мониторинга
    void setLogFile();        // Устанавливает файл для логирования
    void showLogContents();   // Показывает содержимое лог-файла
    void updateLogDisplay();  // Обновляет отображение лога на UI

private:
    void updateDirectoryList();  // Обновляет список мониторящих директорий на UI

    Ui::MainWindow *ui;                         // Указатель на UI, сгенерированный Qt Designer
    smart_ptr<DirectoryMonitor> monitor;       // Умный указатель на объект DirectoryMonitor
};

#endif // MAINWINDOW_H
