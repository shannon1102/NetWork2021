#include "loginscreen.h"
#include "ui_loginscreen.h"

LoginScreen::LoginScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}


void LoginScreen::on_pushButton_clicked()
{
//    loginScreen = new LoginScreen(this);
//    loginScreen->hide();
    homeScreen = new HomeScreen(this);
    homeScreen->show();
}

