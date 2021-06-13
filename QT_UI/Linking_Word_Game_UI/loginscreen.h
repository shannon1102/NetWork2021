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

public slots:

//    void on_lineEdit_user_editingFinished();

//    void on_lineEdit_pass_editingFinished();

private:
    Ui::LoginScreen *ui;
    HomeScreen homeScreen;
};
#endif // LOGINSCREEN_H
