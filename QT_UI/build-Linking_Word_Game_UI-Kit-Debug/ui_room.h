/********************************************************************************
** Form generated from reading UI file 'room.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOM_H
#define UI_ROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_room
{
public:
    QListWidget *listWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QDialog *room)
    {
        if (room->objectName().isEmpty())
            room->setObjectName(QString::fromUtf8("room"));
        room->resize(900, 621);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(room->sizePolicy().hasHeightForWidth());
        room->setSizePolicy(sizePolicy);
        room->setMinimumSize(QSize(900, 621));
        listWidget = new QListWidget(room);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(80, 200, 751, 331));
        label = new QLabel(room);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-50, 0, 961, 101));
        label_2 = new QLabel(room);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(660, 560, 181, 31));
        label_2->setStyleSheet(QString::fromUtf8("font-family: Roboto;\n"
"font-style: normal;\n"
"font-weight: 900;\n"
"font-size: 30px;\n"
"line-height: 42px;\n"
"\n"
"color: #FF0000;"));
        pushButton = new QPushButton(room);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 550, 250, 50));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(250, 50));
        pushButton->setStyleSheet(QString::fromUtf8("background: #FFFFFF;\n"
"border: 1px solid #000000;\n"
"box-sizing: border-box;\n"
"border-radius: 24px;\n"
"font-family: Roboto;\n"
"font-style: normal;\n"
"font-weight: 900;\n"
"font-size: 30px;\n"
"line-height: 42px;\n"
"\n"
"color: #FF0000;"));
        label_3 = new QLabel(room);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 140, 161, 31));
        label_3->setStyleSheet(QString::fromUtf8("font-family: Roboto;\n"
"font-style: normal;\n"
"font-weight: 900;\n"
"font-size: 30px;\n"
"line-height: 42px;\n"
"\n"
"color: blue;"));

        retranslateUi(room);

        QMetaObject::connectSlotsByName(room);
    } // setupUi

    void retranslateUi(QDialog *room)
    {
        room->setWindowTitle(QApplication::translate("room", "Room", nullptr));
        label->setText(QApplication::translate("room", "<html><head/><body><p><img src=\":/resource/image/logo-removebg-preview (2).png\"/></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("room", "Room code", nullptr));
        pushButton->setText(QApplication::translate("room", "Start Game", nullptr));
        label_3->setText(QApplication::translate("room", "Player List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class room: public Ui_room {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOM_H
