// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hangmangame.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void on_validateButton_clicked();
    void updateUsedLetters(const QString &letters);
    void updateHiddenWord(QString word);

private:
    Ui::MainWindow *ui;
    HangmanGame *hangmanGame;
};

#endif // MAINWINDOW_H
