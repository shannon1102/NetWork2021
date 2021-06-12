/********************************************************************************
** Form generated from reading UI file 'homescreen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMESCREEN_H
#define UI_HOMESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeScreen
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_2;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit;
    QFrame *frame_6;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *HomeScreen)
    {
        if (HomeScreen->objectName().isEmpty())
            HomeScreen->setObjectName(QString::fromUtf8("HomeScreen"));
        HomeScreen->resize(1000, 621);
        HomeScreen->setStyleSheet(QString::fromUtf8("background: #F9F9F9;"));
        centralwidget = new QWidget(HomeScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(frame, 0, Qt::AlignHCenter);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(400, 55));
        pushButton->setStyleSheet(QString::fromUtf8("background: #F9F9F9;\n"
"border: 2px solid #000000;\n"
"box-sizing: border-box;\n"
"border-radius: 24px;\n"
"font-family: Roboto;\n"
"font-style: normal;\n"
"font-weight: 900;\n"
"font-size: 30px;\n"
"line-height: 42px;\n"
"display: flex;\n"
"align-items: center;\n"
"text-align: center;\n"
"\n"
"color: #DF0707;"));

        horizontalLayout_2->addWidget(pushButton, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background: #F9F9F9;"));

        horizontalLayout_4->addWidget(label_2, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(frame_3);

        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_2 = new QPushButton(frame_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(400, 55));
        pushButton_2->setStyleSheet(QString::fromUtf8("background: #F9F9F9;\n"
"border: 2px solid #000000;\n"
"box-sizing: border-box;\n"
"border-radius: 24px;\n"
"font-family: Roboto;\n"
"font-style: normal;\n"
"font-weight: 900;\n"
"font-size: 30px;\n"
"line-height: 42px;\n"
"display: flex;\n"
"align-items: center;\n"
"text-align: center;\n"
"\n"
"color: #0743DF;"));

        horizontalLayout_5->addWidget(pushButton_2, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(frame_4);

        frame_5 = new QFrame(centralwidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_7 = new QFrame(frame_5);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_7);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lineEdit = new QLineEdit(frame_7);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(700, 50));
        lineEdit->setStyleSheet(QString::fromUtf8("background: #F9F9F9;\n"
"border: 2px solid #000000;\n"
"box-sizing: border-box;\n"
"border-radius: 20px;\n"
"font-family: Roboto;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 36px;\n"
"line-height: 42px;\n"
"display: flex;\n"
"align-items: center;\n"
"padding-left: 30px;\n"
"text-align: center;\n"
"\n"
"color: #000000;"));
        lineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit, 0, Qt::AlignHCenter);


        verticalLayout_2->addWidget(frame_7);


        horizontalLayout_3->addLayout(verticalLayout_2);

        frame_6 = new QFrame(frame_5);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        sizePolicy.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy);
        frame_6->setMinimumSize(QSize(55, 55));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        pushButton_3 = new QPushButton(frame_6);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 0, 51, 55));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(42, 50));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-image: url(:/resource/image/3132-200.png);"));

        horizontalLayout_3->addWidget(frame_6, 0, Qt::AlignBottom);


        verticalLayout->addWidget(frame_5);

        HomeScreen->setCentralWidget(centralwidget);

        retranslateUi(HomeScreen);

        QMetaObject::connectSlotsByName(HomeScreen);
    } // setupUi

    void retranslateUi(QMainWindow *HomeScreen)
    {
        HomeScreen->setWindowTitle(QApplication::translate("HomeScreen", "MainWindow", nullptr));
        label->setText(QApplication::translate("HomeScreen", "<html><head/><body><p><img src=\":/resource/image/logo-removebg-preview (2).png\"/></p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("HomeScreen", "Create a new room", nullptr));
        label_2->setText(QApplication::translate("HomeScreen", "<html><head/><body><p><img src=\":/resource/image/Untitled.png\"/></p></body></html>", nullptr));
        pushButton_2->setText(QApplication::translate("HomeScreen", "Join an existing room", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("HomeScreen", "Enter room code here", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("HomeScreen", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Sign Out</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HomeScreen: public Ui_HomeScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMESCREEN_H
