#include "dataManager.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open Dictionary File"));
    if ( !path.isNull() )
    {
        dataManager = new DataManager(path);
        dataManager->getNewWord();
    }

    ui->setupUi(this);

    scene = new QGraphicsScene();

    font = new QFont("Courier");
    font->setStyleHint(QFont::TypeWriter);
    font->setPointSize(42);
    font->setUnderline(true);
    scene->addText(dataManager->getDisplayWord(), *font);

    ui->graphicsView->setScene(scene);

    redrawNumAttempts();
    redrawNumAttemptsLeft();
}

MainWindow::MainWindow(const QString& path, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    dataManager = new DataManager(path);
    dataManager->getNewWord();

    ui->setupUi(this);

    scene = new QGraphicsScene();

    font = new QFont("Courier");
    font->setStyleHint(QFont::TypeWriter);
    font->setPointSize(42);
    font->setUnderline(true);
    scene->addText(dataManager->getDisplayWord(), *font);

    ui->graphicsView->setScene(scene);

    redrawNumAttempts();
    redrawNumAttemptsLeft();
}

MainWindow::~MainWindow()
{
    delete font;
    delete scene;
    delete ui;
    delete dataManager;
}

void MainWindow::on_buttonEnter_clicked()
{
    on_inputChar_returnPressed();
}

void MainWindow::on_inputChar_returnPressed()
{
    if (!dataManager->hasGivenUp())
    {
        if (ui->inputChar->text() != "")
        {
            QChar input = ui->inputChar->text().at(0);
            ui->attemptedChars->setText(input);
            update(input);

            ui->inputChar->setText("");
        }
    }
}

void MainWindow::on_buttonNewWord_clicked()
{
    dataManager->reset();
    scene->clear();
    scene->addText(dataManager->getDisplayWord(), *font);
    ui->attemptedChars->setText("");
    ui->inputChar->setText("");
    redrawNumAttempts();
    redrawNumAttemptsLeft();
}

void MainWindow::on_buttonResign_clicked()
{
    dataManager->giveUp();
    redrawWord();
}

void MainWindow::on_buttonHint_clicked()
{
    dataManager->getHint();
    redrawAttemptedCharBox();
    redrawWord();
}

void MainWindow::update(QChar input)
{
    if (!dataManager->hasGivenUp())
    {
        dataManager->charAdd(input);
        redrawAttemptedCharBox();
        redrawWord();
        redrawNumAttempts();
        redrawNumAttemptsLeft();
    }
}

void MainWindow::redrawAttemptedCharBox()
{
    ui->attemptedChars->setText(dataManager->getAttemptedLetters());
}

void MainWindow::redrawWord()
{
    scene->clear();
    scene->addText(dataManager->getDisplayWord(), *font);
}

void MainWindow::redrawNumAttempts()
{
    ui->labelNumAttempts->setText("Total des tentatives: " + QString::number(dataManager->getNumAttempts()));

}

void MainWindow::redrawNumAttemptsLeft()
{
    ui->labelAttemptsLeft->setText("Tentatives restantes: " + QString::number(dataManager->getAttemptsLeft()));
}
