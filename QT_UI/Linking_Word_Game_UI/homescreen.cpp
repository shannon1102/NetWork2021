#include "homescreen.h"
#include "ui_homescreen.h"
#include "room.h"
#include "QMessageBox"
#include <QApplication>
#include <QProcess>
extern QString user;
extern bool clicked;

HomeScreen::HomeScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeScreen)
{
    ui->setupUi(this);
    ui->lineEdit->setText(user);
}

HomeScreen::~HomeScreen()
{
    delete ui;
}




void HomeScreen::on_pushButton_clicked()
{
    room room1;
    room1.setModal(true);
    room1.exec();
    if (clicked) this->hide();
    clicked = 0;
}



void HomeScreen::on_lineEdit_returnPressed()
{
    if (ui->lineEdit->displayText()=="haha")
    {
        room room1;
        room1.setModal(true);
        room1.exec();
        if (clicked) this->hide();
        clicked = 0;
    }
    else
    {
        QMessageBox::warning(this,"Notify","No Room Code Exist");
    }

}

void HomeScreen::on_pushButton_3_clicked()
{
//       loginscreen.show();
    this->hide();
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}
