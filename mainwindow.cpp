// mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hangmangame.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hangmanGame = new HangmanGame(this);

    // Connecter le signal de HangmanGame au slot de MainWindow
    connect(hangmanGame, &HangmanGame::hiddenWordUpdated, this, &MainWindow::updateHiddenWord);
    connect(hangmanGame, &HangmanGame::usedLettersUpdated, this, &MainWindow::updateUsedLetters);
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

void MainWindow::on_validateButton_clicked()
{
    QString guess = ui->guessLineEdit->text().toUpper().trimmed(); // Récupérer la lettre saisie
    ui->guessLineEdit->clear(); // Effacer le texte de la ligne de saisie
    hangmanGame->processGuess(guess); // Traiter la lettre saisie
}

void MainWindow::updateUsedLetters(const QString &letters)
{
    ui->usedLettersLabel->setText("Lettres déjà utilisées : " + letters);
}
