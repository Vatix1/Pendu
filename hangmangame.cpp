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
    // Ne pas appeler gameLoop() ici, cela devrait être géré par les signaux et les slots
}

void HangmanGame::gameLoop()
{
    // Ne plus utiliser de boucle, la logique de jeu sera gérée par les signaux et les slots
}

void HangmanGame::displayGameStatus()
{
    qDebug() << "Word:" << hiddenWord;
    qDebug() << "Attempts left:" << attemptsLeft;
    qDebug() << "Used letters:" << usedLetters.values().join(',');
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

    emit hiddenWordUpdated(hiddenWord);
    emit usedLettersUpdated(usedLetters.values().join(','));
}
