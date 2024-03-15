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
public slots:
            void updateHiddenWord(QString word);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
            void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    HangmanGame *hangmanGame;
};

#endif // MAINWINDOW_H
