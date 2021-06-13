#include "loginscreen.h"
#include "ui_loginscreen.h"
#include <QString>

QString user;
QString passwd;

LoginScreen::LoginScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}


void LoginScreen::on_pushButton_clicked()
{
    homeScreen.show();
    this->hide();
}

void LoginScreen::on_lineEdit_user_editingFinished()
{
    user = ui->lineEdit_user->text();
}



void LoginScreen::on_lineEdit_pass_editingFinished()
{
    passwd = ui->lineEdit_pass->text();
}

//extern void LoginScreen::changeWindow(QMainWindow q1, QMainWindow q2)
//{
//    q1.hide();
//    q2.show();
//}

