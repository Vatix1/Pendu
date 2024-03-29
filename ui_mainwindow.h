/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionChoose_New_Word_List;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *buttonEnter;
    QLineEdit *inputChar;
    QLabel *labelAttempted;
    QTextBrowser *attemptedChars;
    QPushButton *buttonResign;
    QPushButton *buttonNewWord;
    QPushButton *buttonHint;
    QWidget *widget;
    QGraphicsView *graphicsView;
    QLabel *labelNumAttempts;
    QLabel *labelAttemptsLeft;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuChoose_Word_List;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(577, 414);
        actionChoose_New_Word_List = new QAction(MainWindow);
        actionChoose_New_Word_List->setObjectName("actionChoose_New_Word_List");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 200, 551, 141));
        buttonEnter = new QPushButton(groupBox);
        buttonEnter->setObjectName("buttonEnter");
        buttonEnter->setGeometry(QRect(220, 90, 71, 31));
        inputChar = new QLineEdit(groupBox);
        inputChar->setObjectName("inputChar");
        inputChar->setGeometry(QRect(230, 50, 51, 20));
        inputChar->setMaxLength(1);
        inputChar->setAlignment(Qt::AlignCenter);
        labelAttempted = new QLabel(groupBox);
        labelAttempted->setObjectName("labelAttempted");
        labelAttempted->setGeometry(QRect(60, 10, 81, 16));
        attemptedChars = new QTextBrowser(groupBox);
        attemptedChars->setObjectName("attemptedChars");
        attemptedChars->setGeometry(QRect(30, 30, 121, 91));
        buttonResign = new QPushButton(groupBox);
        buttonResign->setObjectName("buttonResign");
        buttonResign->setGeometry(QRect(360, 50, 131, 31));
        buttonNewWord = new QPushButton(groupBox);
        buttonNewWord->setObjectName("buttonNewWord");
        buttonNewWord->setGeometry(QRect(360, 90, 131, 31));
        buttonHint = new QPushButton(groupBox);
        buttonHint->setObjectName("buttonHint");
        buttonHint->setGeometry(QRect(360, 10, 131, 31));
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 461, 181));
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(80, 0, 391, 151));
        labelNumAttempts = new QLabel(widget);
        labelNumAttempts->setObjectName("labelNumAttempts");
        labelNumAttempts->setGeometry(QRect(10, 160, 131, 16));
        labelAttemptsLeft = new QLabel(widget);
        labelAttemptsLeft->setObjectName("labelAttemptsLeft");
        labelAttemptsLeft->setGeometry(QRect(160, 160, 161, 16));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 577, 24));
        menuChoose_Word_List = new QMenu(menuBar);
        menuChoose_Word_List->setObjectName("menuChoose_Word_List");
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName("menuAbout");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuChoose_Word_List->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuChoose_Word_List->addAction(actionChoose_New_Word_List);
        menuAbout->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Hangman", nullptr));
        actionChoose_New_Word_List->setText(QCoreApplication::translate("MainWindow", "Choose New Word List", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        groupBox->setTitle(QString());
        buttonEnter->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        labelAttempted->setText(QCoreApplication::translate("MainWindow", "D\303\251j\303\240 tent\303\251", nullptr));
        buttonResign->setText(QCoreApplication::translate("MainWindow", "Avoir la r\303\251ponse", nullptr));
        buttonNewWord->setText(QCoreApplication::translate("MainWindow", "Nouveau mot !", nullptr));
        buttonHint->setText(QCoreApplication::translate("MainWindow", "Avoir un indice", nullptr));
        labelNumAttempts->setText(QCoreApplication::translate("MainWindow", "Tentatives totales\302\240: 0", nullptr));
        labelAttemptsLeft->setText(QCoreApplication::translate("MainWindow", "Tentatives restantes\302\240:", nullptr));
        menuChoose_Word_List->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
