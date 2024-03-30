#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <time.h>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //init
    srand(time(NULL));
    //generate
    secretNum =rand()%100+1;
    qDebug()<<"secret number generated :" << QString::number((secretNum));
    ui->pushButton_2->setDisabled(true);
    ui->label_2->setText("");

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    guessNum=ui->spinBox->value();
    qDebug()<<"the guess number is :" << QString ::number((guessNum));
    if (guessNum == secretNum)
    {
        ui->label_2->setText("Congrats , You guessed the right number : " +QString::number(secretNum));
        ui->pushButton->setDisabled(true);
        ui->pushButton_2->setDisabled(false);

    }else {
        if (secretNum < guessNum)
        {
            ui->label_2->setText("Too high , Try again");

        }
        if (secretNum > guessNum)
        {
            ui->label_2->setText("Too low , Try again");
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton->setDisabled(false);
    ui->pushButton_2->setDisabled(true);
    ui->spinBox->setValue(1);
    secretNum =rand()%100+1;
    ui->label_2->setText("");

}

