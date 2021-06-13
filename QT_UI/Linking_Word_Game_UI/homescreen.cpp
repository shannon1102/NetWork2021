#include "homescreen.h"
#include "ui_homescreen.h"
#include "room.h"
#include "QMessageBox"
#include <QApplication>
#include <QProcess>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <QDebug>
#include <QString>


extern QString name;
extern QString pass;
extern int sockfd;
extern bool clicked;

HomeScreen::HomeScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeScreen)
{
    ui->setupUi(this);
    printf("%s\n",name);
}

HomeScreen::~HomeScreen()
{
    delete ui;
}




void HomeScreen::on_pushButton_clicked()
{
    QString msg = {"GAMES"};
//    QString full_msg = msg+pass;
    QByteArray ba = msg.toLocal8Bit();
    const char *c_str2 = ba.data();
    printf("str2: %s", c_str2);
    printf("%s\n",name);
    qDebug ("message %s, says: %s",name,name);
//    send(sockfd,full_msg,1024,0);
    send(sockfd,c_str2,1024,0);
    room room1;
    room1.setModal(true);
    room1.exec();
    if (clicked) this->hide();
    clicked = 0;
}



void HomeScreen::on_lineEdit_returnPressed()
{
//    if (ui->lineEdit->displayText()=="haha")
//    {
    //    ui->lineEdit->text() = name;
    //    if (!ui->lineEdit->text().isEmpty())
        QString room_id = ui->lineEdit->text();
        QString msg = QString("JOIN %1").arg(room_id);

//        QString full_msg = msg.;
        QByteArray ba = msg.toLocal8Bit();
        const char *c_str2 = ba.data();
    //    printf("str2: %s", c_str2);
    //    printf("%s\n",name);
        //qDebug ("message %s, says:",room_id);
        qDebug() << QString("%1").arg(msg);
        send(sockfd,c_str2,1024,0);
//       send(sockfd,c_str2,1024,0);
        room room1;
        room1.setModal(true);
        room1.exec();
        if (clicked) this->hide();
        clicked = 0;
//    }
//    else
//    {
//        QMessageBox::warning(this,"Notify","No Room Code Exist");
//    }

}

void HomeScreen::on_pushButton_3_clicked()
{
//       loginscreen.show();
//    this->hide();
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}
