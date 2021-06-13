#include "loginscreen.h"
#include "homescreen.h"
#include "playscreen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    LoginScreen w;
//    HomeScreen w;
    PlayScreen w;
    w.show();
    return a.exec();
}
