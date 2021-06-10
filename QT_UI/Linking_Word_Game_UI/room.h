#ifndef ROOM_H
#define ROOM_H

#include <QDialog>
#include "playscreen.h"

namespace Ui {
class room;
}

class room : public QDialog
{
    Q_OBJECT

public:
    explicit room(QWidget *parent = nullptr);
    ~room();

private slots:
    void on_pushButton_clicked();

private:
    Ui::room *ui;
    PlayScreen *playSreen;
};

#endif // ROOM_H
