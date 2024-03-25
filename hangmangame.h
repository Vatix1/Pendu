#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <QObject>
#include <QSet>
#include <QString>
#include <QStringList>

class HangmanGame : public QObject
{
    Q_OBJECT

public:
    HangmanGame(QObject *parent = nullptr);

    void startGame();
    void processGuess(const QString &guess); // Déplacer la déclaration dans la section public

private slots:
    void gameLoop();

private:
    void displayGameStatus();
    QString askForGuess();

    QStringList words;
    QString currentWord;
    QString hiddenWord;
    QSet<QString> usedLetters;
    int maxAttempts;
    int attemptsLeft;

signals:
    void hiddenWordUpdated(QString word);
    void usedLettersUpdated(const QString letters);

};

#endif // HANGMANGAME_H
