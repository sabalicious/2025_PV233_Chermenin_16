QT       += core gui widgets

CONFIG   += c++17

TARGET = DirectoryMonitorApp
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h \
    DirectoryMonitor.h \
    SmartPtr.h

FORMS += \
    mainwindow.ui
