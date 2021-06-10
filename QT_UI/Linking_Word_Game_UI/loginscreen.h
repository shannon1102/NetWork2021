#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QMainWindow>
#include <homescreen.h>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginScreen; }
QT_END_NAMESPACE

class LoginScreen : public QMainWindow
{
    Q_OBJECT

public:
    LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginScreen *ui;
    HomeScreen *homeScreen;
    LoginScreen *loginScreen;
};
#endif // LOGINSCREEN_H
