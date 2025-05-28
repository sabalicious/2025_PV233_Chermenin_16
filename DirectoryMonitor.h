#ifndef DIRECTORYMONITOR_H
#define DIRECTORYMONITOR_H

#include "smartptr.h"
#include <QObject>
#include <QFileSystemWatcher>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

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

    void addDirectory(const QString &path) {
        if (path.isEmpty()) return;

        if (!watcher->directories().contains(path)) {
            watcher->addPath(path);
            logChange(QString("Начат мониторинг директории: '%1'").arg(path));
        }
    }

    void removeDirectory(const QString &path) {
        if (watcher->directories().contains(path)) {
            watcher->removePath(path);
            logChange(QString("Прекращён мониторинг директории: '%1'").arg(path));
        }
    }

    QStringList monitoredDirectories() const {
        return watcher->directories();
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
            // Не удалось открыть файл — можно добавить отладочный вывод, если надо
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
