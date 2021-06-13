#include "playscreen.h"
#include "ui_playscreen.h"
#include <QString>
#include <QTime>
#include <QList>
#include <QColor>
#include <QMessageBox>
#include "homescreen.h"

extern QString name;
extern QString pass;
int turn;
QString text;
QTime maxTime(0,5,0);
QTime minTime(0,0,0);


PlayScreen::PlayScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayScreen)
{
    ui->setupUi(this);
    for (int i= 0; i<4;i++)
    {
        player.append("a");
        player[i] = QString("Player #%1  ").arg(i);
        c_clock.append(maxTime);
    }
    ui->player_1->setText(player[0]);
    ui->player_2->setText(player[1]);
    ui->player_3->setText(player[2]);
    ui->player_4->setText(player[3]);
    ui->time_1->setText(c_clock[0].toString("m:ss"));
    ui->time_2->setText(c_clock[1].toString("m:ss"));
    ui->time_3->setText(c_clock[2].toString("m:ss"));
    ui->time_4->setText(c_clock[3].toString("m:ss"));
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCountdown()));
    text.append(name);
//    text.append("dfsadfadsfaudfauisdf");

    ui->label_3->setText(text);


}

PlayScreen::~PlayScreen()
{
    delete ui;
}

void PlayScreen::on_lineEdit_returnPressed()
{
    turn = ui->lineEdit->text().toInt()-1;
//    if ((turn<0)||(turn>3)) turn = 0;
}

void PlayScreen::updateCountdown()
{
    c_clock[turn] = c_clock[turn].addSecs(-1);
    switch (turn)
    {
        case 0: ui->time_1->setText(c_clock[turn].toString("m:ss")); break;
        case 1: ui->time_2->setText(c_clock[turn].toString("m:ss")); break;
        case 2: ui->time_3->setText(c_clock[turn].toString("m:ss")); break;
        case 3: ui->time_4->setText(c_clock[turn].toString("m:ss")); break;
    }

    if (c_clock[turn] == minTime)
    {
        QMessageBox::warning(this,"Time Out", "You loss the game");

    }
//    ui->time_1->setText(c_clock[0].toString("m:ss"));
//    ui->time_2->setText(c_clock[1].toString("m:ss"));
//    ui->time_3->setText(c_clock[2].toString("m:ss"));
//    ui->time_4->setText(c_clock[3].toString("m:ss"));
}


void PlayScreen::on_pushButton_clicked()
{
    HomeScreen *homescreen = new HomeScreen();
    homescreen->show();
//    homeScreen.show();
    this->hide();
}


void PlayScreen::on_pushButton_2_clicked()
{
    timer->start(1000);
}

