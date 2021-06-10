#include "room.h"
#include "ui_room.h"

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

    playSreen = new PlayScreen(this);
    playSreen->show();
}

