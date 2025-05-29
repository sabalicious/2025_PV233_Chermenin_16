#ifndef DIRECTORYMONITOR_H
#define DIRECTORYMONITOR_H

#include "smartptr.h"
#include <QObject>
#include <QFileSystemWatcher>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDir>

class DirectoryMonitor : public QObject {
    Q_OBJECT

public:
    explicit DirectoryMonitor(QObject *parent = nullptr)
        : QObject(parent), watcher(new QFileSystemWatcher(this))
    {
        // Подключаем сигналы QFileSystemWatcher к методам логирования
        connect(watcher.get(), &QFileSystemWatcher::directoryChanged, this, &DirectoryMonitor::logDirectoryChange);
        connect(watcher.get(), &QFileSystemWatcher::fileChanged, this, &DirectoryMonitor::logFileChange);
    }

    void setLogFile(const QString &path) {
        logFilePath = path.trimmed();
    }

    const QString& getLogFilePath() const {
        return logFilePath;
    }

    bool addPath(const QString &path) {
        if (path.isEmpty()) return false;

        QFileInfo fileInfo(path);
        if (!fileInfo.exists()) {
            return false;
        }

        QString absolutePath = fileInfo.absoluteFilePath();
        
        // Проверяем, не отслеживается ли уже этот путь
        if (watcher->directories().contains(absolutePath) || 
            watcher->files().contains(absolutePath)) {
            return false;
        }

        if (fileInfo.isDir()) {
            if (watcher->addPath(absolutePath)) {
                logChange(QString("Начат мониторинг директории: '%1'").arg(absolutePath));
                return true;
            }
        } else {
            if (watcher->addPath(absolutePath)) {
                logChange(QString("Начат мониторинг файла: '%1'").arg(absolutePath));
                return true;
            }
        }
        return false;
    }

    void removePath(const QString &path) {
        QFileInfo fileInfo(path);
        QString absolutePath = fileInfo.absoluteFilePath();
        
        if (watcher->directories().contains(absolutePath) || 
            watcher->files().contains(absolutePath)) {
            watcher->removePath(absolutePath);
            logChange(QString("Прекращён мониторинг: '%1'").arg(absolutePath));
        }
    }

    QStringList monitoredPaths() const {
        QStringList allPaths;
        allPaths << watcher->directories() << watcher->files();
        return allPaths;
    }

signals:
    void logUpdated();

private slots:
    void logDirectoryChange(const QString &path) {
        logChange(QString("Обнаружено изменение в директории: '%1'").arg(path));
        emit logUpdated();
    }

    void logFileChange(const QString &path) {
        logChange(QString("Обнаружено изменение в файле: '%1'").arg(path));
        emit logUpdated();
    }

private:
    void logChange(const QString &message) {
        if (logFilePath.isEmpty()) return;

        smart_ptr<QFile> file(new QFile(logFilePath));
        if (!file->open(QIODevice::Append | QIODevice::Text)) {
            // Не удалось открыть файл
            return;
        }

        QTextStream stream(file.get());
        QString timestamp = QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss");
        stream << timestamp << " | " << message << "\n";
    }

    smart_ptr<QFileSystemWatcher> watcher;
    QString logFilePath;
};

#endif // DIRECTORYMONITOR_H
