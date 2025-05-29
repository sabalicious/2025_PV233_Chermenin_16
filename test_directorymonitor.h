#ifndef TEST_DIRECTORYMONITOR_H
#define TEST_DIRECTORYMONITOR_H

#include <QTest>
#include <QSignalSpy>
#include <QTemporaryFile>
#include "DirectoryMonitor.h"

class TestDirectoryMonitor : public QObject
{
    Q_OBJECT

private slots:
    void testLogFileChange()
    {
        // Создаем временный файл для логов
        QTemporaryFile logFile;
        QVERIFY(logFile.open());
        QString logFilePath = logFile.fileName();
        logFile.close();

        // Создаем временный файл для мониторинга
        QTemporaryFile testFile;
        QVERIFY(testFile.open());
        QString testFilePath = testFile.fileName();
        testFile.close();

        // Создаем монитор и настраиваем его
        DirectoryMonitor monitor;
        monitor.setLogFile(logFilePath);
        monitor.addDirectory(QFileInfo(testFilePath).path());

        // Создаем шпион для сигнала logUpdated
        QSignalSpy spy(&monitor, &DirectoryMonitor::logUpdated);

        // Изменяем файл
        QFile file(testFilePath);
        QVERIFY(file.open(QIODevice::WriteOnly));
        file.write("test content");
        file.close();

        // Ждем немного, чтобы QFileSystemWatcher успел обработать изменение
        QTest::qWait(100);

        // Проверяем, что сигнал был отправлен
        QCOMPARE(spy.count(), 1);

        // Проверяем содержимое лог-файла
        QFile log(logFilePath);
        QVERIFY(log.open(QIODevice::ReadOnly));
        QString logContent = log.readAll();
        QVERIFY(logContent.contains("Обнаружено изменение в файле"));
        QVERIFY(logContent.contains(testFilePath));
    }
};

#endif // TEST_DIRECTORYMONITOR_H 