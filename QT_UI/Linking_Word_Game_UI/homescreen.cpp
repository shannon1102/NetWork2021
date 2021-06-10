#include "homescreen.h"
#include "ui_homescreen.h"
#include "room.h"
#include "QMessageBox"
#include <QApplication>
#include <QProcess>

HomeScreen::HomeScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeScreen)
{
    ui->setupUi(this);
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
}



void HomeScreen::on_lineEdit_returnPressed()
{
    if (ui->lineEdit->displayText()=="haha")
    {
        room room1;
        room1.setModal(true);
        room1.exec();
    }
    else
    {
        QMessageBox::warning(this,"Notify","No Room Code Exist");
    }

}

void HomeScreen::on_pushButton_3_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}
