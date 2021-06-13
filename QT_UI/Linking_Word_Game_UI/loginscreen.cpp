#include "loginscreen.h"
#include "ui_loginscreen.h"
#include <QString>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include<QDebug>

extern int sockfd;
QString name;
QString pass;

LoginScreen::LoginScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
    //    ui->lineEdit_pass.setText();
    ui->lineEdit_user->displayText()=="Alo";
}

LoginScreen::~LoginScreen()
{
    delete ui;
}


void LoginScreen::on_pushButton_clicked()
{
    name = ui->lineEdit_user->text();
    pass = ui->lineEdit_pass->text();
    QString msg = {"LOGIN "};
    QString full_msg = msg+pass;
    QByteArray ba = full_msg.toLocal8Bit();
    const char *c_str2 = ba.data();
    printf("str2: %s", c_str2);
    printf("%s\n",name);
    qDebug ("message %s, says: %s",name,name);
//  send(sockfd,full_msg,1024,0);
    send(sockfd,c_str2,1024,0);
    homeScreen.show();
    this->hide();
}

//void LoginScreen::on_lineEdit_user_editingFinished()
//{
//    user = ui->lineEdit_user->text();
//}



//void LoginScreen::on_lineEdit_pass_editingFinished()
//{
//    passwd = ui->lineEdit_pass->text();
//}

//extern void LoginScreen::changeWindow(QMainWindow q1, QMainWindow q2)
//{
//    q1.hide();
//    q2.show();
//}

