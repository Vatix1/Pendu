#include "dataManager.h"
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QTextStream>
#include <QRandomGenerator>

DataManager::DataManager(QString dictionary)
{
    numAttempts = 0;
    showWord = false;

    fillWordList(dictionary);

    resetNumAttempted();
}

void DataManager::charAdd(const QChar& charInput, bool b)
{
    if (!charInput.isLetter())
        return;

    QChar input = charInput.toUpper();

    for (std::vector<QChar>::iterator it = attemptedChars.begin();
         it != attemptedChars.end();
         ++it)
    {
        if (input == *it)
            return;

        if (input < *it)
        {
            attemptedChars.insert(it, input);
            numAttempts++;
            if (b)
                updateAttemptsLeft(input);
            return;
        }
    }

    attemptedChars.push_back(input);
    numAttempts++;

    if (b)
        updateAttemptsLeft(input);
}

void DataManager::fillWordList(QString fileName)
{
    QString temp;
    QFile fileStream(fileName);
    if (!fileStream.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "File Error", fileStream.errorString());
        return;
    }
    QTextStream textStream(&fileStream);
    while (!textStream.atEnd())
    {
        textStream >> temp;
        temp = temp.toUpper();
        wordList.push_back(temp);
    }
    fileStream.close();
}

QString DataManager::getAttemptedLetters()
{
    QString returnString;
    for (uint8_t i = 0; i < attemptedChars.size(); i++)
    {
        returnString += attemptedChars.at(i);
    }
    return returnString;
}

QString DataManager::getWord()
{
    return word;
}

QString DataManager::getDisplayWord()
{
    if (showWord) return word;

    QString returnString;

    for (uint8_t i = 0; i < word.length(); i++)
    {
        bool found = false;
        for (uint8_t j = 0; j < attemptedChars.size(); j++)
        {
            if (word.at(i) == attemptedChars.at(j))
            {
                returnString += attemptedChars.at(j);
                found = true;
                break;
            }
        }
        if (word.at(i) == '-')
            returnString += "-";
        else if (!found)
        {
            returnString += " ";
        }
    }

    return returnString;
}

void DataManager::getNewWord()
{
    int randomIndex = QRandomGenerator::global()->generate() % wordList.size();
    word = wordList.at(randomIndex);
    attemptedChars.clear();
}

void DataManager::giveUp()
{
    showWord = true;
}

bool DataManager::hasGivenUp()
{
    return showWord;
}

int DataManager::getNumAttempts()
{
    return numAttempts;
}

int DataManager::getAttemptsLeft()
{
    return numAttemptsLeft;
}

void DataManager::reset()
{
    numAttempts = 0;
    resetNumAttempted();
    getNewWord();
    showWord = false;
}

void DataManager::updateAttemptsLeft(QChar input)
{
    bool remove = true;
    for (int i = 0; i < word.size(); i++)
    {
        if (word.at(i) == input)
        {
            remove = false;
        }
    }
    if (remove)
        numAttemptsLeft--;

    if (numAttemptsLeft <= 0)
        giveUp();
}

void DataManager::resetNumAttempted()
{
    numAttemptsLeft = 5 + int(word.size()/26.0 * 10);
}

void DataManager::getHint()
{
    if (showWord) return;

    uint8_t charCounter = 0;
    for (uint8_t i = 0; i < word.size(); i++)
    {
        for (uint8_t j = 0; j < attemptedChars.size(); j++)
        {
            if (word.at(i) == attemptedChars.at(j) || word.at(i) == '-')
            {
                charCounter++;
                break;
            }
        }
    }
    if (charCounter >= word.size()) {
        showWord = true;
        return;
    }

    QChar hintChar;
    do
    {
        hintChar= QChar('A' + char(QRandomGenerator::global()->generate() % ('Z' - 'A')));
    } while (hasBeenGuessed(hintChar) || word.indexOf(hintChar) == -1);
    charAdd(hintChar, false);
}

bool DataManager::hasBeenGuessed(const QChar& input)
{
    for (uint8_t j = 0; j < attemptedChars.size(); j++)
    {
        if (input == attemptedChars.at(j))
        {
            return true;
        }
    }
    return false;
}
