#include "room.h"
#include "ui_room.h"
#include <pthread.h>
#include <QApplication>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

extern int sockfd;
bool clicked;

room::room(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::room)
{
    ui->setupUi(this);
}

room::~room()
{
    delete ui;
}

void room::on_pushButton_clicked()
{
    QString msg = {"START"};
    QByteArray ba = msg.toLocal8Bit();
    const char *c_str2 = ba.data();
 /*   printf("str2: %s", c_str2)*/;

    qDebug ("message %s, says:",c_str2);
//    send(sockfd,full_msg,1024,0);
    send(sockfd,c_str2,1024,0);
    playScreen = new PlayScreen();
    playScreen->show();
    clicked = 1;
    this->hide();
}

