#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hangmangame.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hangmanGame = new HangmanGame(this);
}

void MainWindow::updateHiddenWord(QString word)
{
    ui->hiddenWordLabel->setText(word);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    hangmanGame->startGame();
}

connect(hangmanGame, &HangmanGame::hiddenWordUpdated, this, &MainWindow::updateHiddenWord);

