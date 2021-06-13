#include "room.h"
#include "ui_room.h"

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
    playScreen = new PlayScreen();
    playScreen->show();
    clicked = 1;
    this->hide();
}

