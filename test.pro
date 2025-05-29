QT += testlib
QT -= gui

CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    test_directorymonitor.cpp

HEADERS += \
    DirectoryMonitor.h \
    SmartPtr.h \
    test_directorymonitor.h 