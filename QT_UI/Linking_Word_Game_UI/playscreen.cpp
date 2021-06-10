#include "playscreen.h"
#include "ui_playscreen.h"
#include <QString>
#include <QTime>
#include <QList>
#include <QColor>

PlayScreen::PlayScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayScreen)
{
    ui->setupUi(this);
    QList<QListWidgetItem*> player;
    QList<QTime> c_clock;
    QTime maxTime;
    for (auto i=0;i<=9; i++ )
      {
        QListWidgetItem *item = new QListWidgetItem;
        c_clock.append(maxTime);
        c_clock[i].setHMS(0,5,0);
        QString str1 = c_clock[0].toString("mm:ss");
        auto str = QStringLiteral("Player #%1   ").arg(i);
        str.append(str1);
        player.append(item);
        player[i]->setText(str);
        ui->listWidget->insertItem(i,player[i]);
       }
    player[1]->setBackgroundColor(Qt::green);
}

PlayScreen::~PlayScreen()
{
    delete ui;
}
