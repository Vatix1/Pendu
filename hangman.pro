QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hangman
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dataManager.cpp

HEADERS  += mainwindow.h \
    dataManager.h

FORMS    += mainwindow.ui
