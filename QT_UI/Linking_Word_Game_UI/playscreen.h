#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QList>



namespace Ui {
class PlayScreen;
}

class PlayScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayScreen(QWidget *parent = nullptr);
    ~PlayScreen();

private slots:
    void on_lineEdit_returnPressed();
    void updateCountdown();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PlayScreen *ui;
    QTimer *timer;
    QList<QTime> c_clock;
    QList<QString> player;
};

#endif // PLAYSCREEN_H
