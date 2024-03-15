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

private slots:
            void gameLoop();

private:
    void displayGameStatus();
    QString askForGuess();
    void processGuess(const QString &guess);

    QStringList words;
    QString currentWord;
    QString hiddenWord;
    QSet<QString> usedLetters;
    int maxAttempts;
    int attemptsLeft;

signals:
    void hiddenWordUpdated(QString word);

};

#endif // HANGMANGAME_H
