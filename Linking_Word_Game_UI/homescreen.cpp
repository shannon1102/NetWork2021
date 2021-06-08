#include "homescreen.h"
#include "ui_homescreen.h"
#include "room.h"
#include "QMessageBox"

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



void HomeScreen::on_lineEdit_editingFinished()
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

