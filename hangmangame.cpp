#include "hangmangame.h"
#include <QDebug>
#include <QCoreApplication>
#include <QRandomGenerator>
#include <QTextStream>

HangmanGame::HangmanGame(QObject *parent) : QObject(parent), maxAttempts(6)
{
    words << "HELLO" << "WORLD" << "PYTHON" << "QT" << "PROGRAMMING";
}

void HangmanGame::startGame()
{
    currentWord = words.at(QRandomGenerator::global()->bounded(words.size()));
    hiddenWord.fill('_', currentWord.size());
    usedLetters.clear();
    attemptsLeft = maxAttempts;
    displayGameStatus();
    gameLoop();
}

void HangmanGame::gameLoop()
{
    while (attemptsLeft > 0 && hiddenWord.contains('_')) {
        QString guess = askForGuess();
        processGuess(guess);
        displayGameStatus();
    }

    if (attemptsLeft == 0) {
        qDebug() << "You lose! The word was:" << currentWord;
    } else {
        qDebug() << "Congratulations! You guessed the word:" << currentWord;
    }

    QCoreApplication::quit();
}

void HangmanGame::displayGameStatus()
{
    qDebug() << "Word:" << hiddenWord;
    qDebug() << "Attempts left:" << attemptsLeft;
    qDebug() << "Used letters:" << usedLetters.values().join(',');
}

QString HangmanGame::askForGuess()
{
    QTextStream qtin(stdin);
    qDebug() << "Enter your guess:";
    QString guess = qtin.readLine().toUpper().trimmed();
    return guess;
}

void HangmanGame::processGuess(const QString &guess)
{
    if (guess.size() != 1 || !guess.at(0).isLetter()) {
        qDebug() << "Invalid guess! Please enter a single letter.";
        return;
    }

    if (usedLetters.contains(guess)) {
        qDebug() << "You've already guessed that letter!";
        return;
    }

    usedLetters.insert(guess);

    if (currentWord.contains(guess)) {
        for (int i = 0; i < currentWord.size(); ++i) {
            if (currentWord.at(i) == guess.at(0)) {
                hiddenWord[i] = guess.at(0);
            }
        }
    } else {
        --attemptsLeft;
    }
}

void HangmanGame::processGuess(const QString &guess)
{
    // Mettez à jour le mot caché
    emit hiddenWordUpdated(hiddenWord);
}

