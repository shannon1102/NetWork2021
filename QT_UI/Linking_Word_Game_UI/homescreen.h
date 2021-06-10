#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QMainWindow>

namespace Ui {
class HomeScreen;
}

class HomeScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeScreen(QWidget *parent = nullptr);
    ~HomeScreen();

private slots:
    void on_pushButton_clicked();


    void on_lineEdit_returnPressed();

    void on_pushButton_3_clicked();

private:
    Ui::HomeScreen *ui;
};

#endif // HOMESCREEN_H
