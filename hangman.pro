QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hangman
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    hangmangame.cpp

HEADERS += \
    mainwindow.h \
    hangmangame.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += hangman_fr_FR.ts
