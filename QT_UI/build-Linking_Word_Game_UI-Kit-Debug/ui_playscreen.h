/********************************************************************************
** Form generated from reading UI file 'playscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYSCREEN_H
#define UI_PLAYSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayScreen
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *PlayScreen)
    {
        if (PlayScreen->objectName().isEmpty())
            PlayScreen->setObjectName(QString::fromUtf8("PlayScreen"));
        PlayScreen->resize(1018, 621);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PlayScreen->sizePolicy().hasHeightForWidth());
        PlayScreen->setSizePolicy(sizePolicy);
        PlayScreen->setMinimumSize(QSize(1000, 621));
        PlayScreen->setStyleSheet(QString::fromUtf8("background: #F9F9F9;"));
        centralwidget = new QWidget(PlayScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(1000, 100));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, -10, 960, 91));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(frame, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listWidget = new QListWidget(frame_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setMinimumSize(QSize(100, 100));
        listWidget->setStyleSheet(QString::fromUtf8("font-family: Roboto;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 30px;\n"
"line-height: 56px;\n"
"\n"
"color: #000000;"));
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(listWidget);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
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

        verticalLayout_2->addWidget(pushButton);


        horizontalLayout_2->addLayout(verticalLayout_2);

        plainTextEdit = new QPlainTextEdit(frame_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy2);
        plainTextEdit->setStyleSheet(QString::fromUtf8("font-family: Roboto;\n"
"font-style: normal;\n"
"font-weight: 200;\n"
"font-size: 30px;\n"
"line-height: 56px;\n"
"padding-left: 50px;\n"
"\n"
"color: #000000;"));

        horizontalLayout_2->addWidget(plainTextEdit);


        horizontalLayout->addWidget(frame_2);


        verticalLayout->addLayout(horizontalLayout);

        PlayScreen->setCentralWidget(centralwidget);

        retranslateUi(PlayScreen);

        QMetaObject::connectSlotsByName(PlayScreen);
    } // setupUi

    void retranslateUi(QMainWindow *PlayScreen)
    {
        PlayScreen->setWindowTitle(QApplication::translate("PlayScreen", "PlayScreen", nullptr));
        label->setText(QApplication::translate("PlayScreen", "<html><head/><body><p><img src=\":/resource/image/logo-removebg-preview (2).png\"/></p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("PlayScreen", "Leave Room", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayScreen: public Ui_PlayScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYSCREEN_H
