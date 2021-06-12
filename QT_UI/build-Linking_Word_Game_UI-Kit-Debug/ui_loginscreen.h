/********************************************************************************
** Form generated from reading UI file 'loginscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSCREEN_H
#define UI_LOGINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginScreen
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_user;
    QLineEdit *lineEdit_pass;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_logo;

    void setupUi(QMainWindow *LoginScreen)
    {
        if (LoginScreen->objectName().isEmpty())
            LoginScreen->setObjectName(QString::fromUtf8("LoginScreen"));
        LoginScreen->resize(1000, 621);
        LoginScreen->setStyleSheet(QString::fromUtf8("background: #F9F9F9;"));
        centralwidget = new QWidget(LoginScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setSpacing(30);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(verticalWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Ravie"));
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("\n"
"\n"
"font-weight: normal;\n"
"font-size: 72px;\n"
"line-height: 144.8%;\n"
"/* or 104px */\n"
"\n"
"display: flex;\n"
"align-items: center;\n"
"text-align: center;\n"
"letter-spacing: 0.06em;\n"
"\n"
"color: #EF1010;"));

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        lineEdit_user = new QLineEdit(verticalWidget);
        lineEdit_user->setObjectName(QString::fromUtf8("lineEdit_user"));
        lineEdit_user->setEnabled(true);
        sizePolicy1.setHeightForWidth(lineEdit_user->sizePolicy().hasHeightForWidth());
        lineEdit_user->setSizePolicy(sizePolicy1);
        lineEdit_user->setMinimumSize(QSize(600, 50));
        lineEdit_user->setSizeIncrement(QSize(50, 50));
        lineEdit_user->setBaseSize(QSize(7, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Roboto"));
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lineEdit_user->setFont(font1);
        lineEdit_user->setCursor(QCursor(Qt::IBeamCursor));
        lineEdit_user->setMouseTracking(true);
        lineEdit_user->setToolTipDuration(-1);
        lineEdit_user->setLayoutDirection(Qt::LeftToRight);
        lineEdit_user->setAutoFillBackground(false);
        lineEdit_user->setStyleSheet(QString::fromUtf8("\n"
"background: #F9F9F9;\n"
"border: 2px solid #000000;\n"
"box-sizing: border-box;\n"
"border-radius: 24px;\n"
"font-family: Roboto;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 36px;\n"
"line-height: 42px;\n"
"padding-left: 40px;\n"
"color: #000000;\n"
"\n"
"\n"
""));
        lineEdit_user->setInputMethodHints(Qt::ImhNone);
        lineEdit_user->setMaxLength(20);
        lineEdit_user->setFrame(false);
        lineEdit_user->setCursorPosition(0);
        lineEdit_user->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        lineEdit_user->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEdit_user->setClearButtonEnabled(true);

        verticalLayout->addWidget(lineEdit_user, 0, Qt::AlignHCenter);

        lineEdit_pass = new QLineEdit(verticalWidget);
        lineEdit_pass->setObjectName(QString::fromUtf8("lineEdit_pass"));
        sizePolicy1.setHeightForWidth(lineEdit_pass->sizePolicy().hasHeightForWidth());
        lineEdit_pass->setSizePolicy(sizePolicy1);
        lineEdit_pass->setMinimumSize(QSize(600, 50));
        lineEdit_pass->setCursor(QCursor(Qt::IBeamCursor));
        lineEdit_pass->setMouseTracking(true);
        lineEdit_pass->setStyleSheet(QString::fromUtf8("background: #F9F9F9;\n"
"border: 2px solid #000000;\n"
"box-sizing: border-box;\n"
"border-radius: 24px;\n"
"font-family: Roboto;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 36px;\n"
"padding-left: 40px;\n"
"line-height: 42px;\n"
"\n"
"color: #000000;"));
        lineEdit_pass->setInputMethodHints(Qt::ImhNone);
        lineEdit_pass->setMaxLength(20);
        lineEdit_pass->setEchoMode(QLineEdit::Normal);
        lineEdit_pass->setClearButtonEnabled(true);

        verticalLayout->addWidget(lineEdit_pass, 0, Qt::AlignHCenter);

        widget_3 = new QWidget(verticalWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("background: #F9F9F9;"));
        horizontalLayout_6 = new QHBoxLayout(widget_3);
        horizontalLayout_6->setSpacing(145);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_6->setContentsMargins(-1, 0, -1, 64);
        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(225, 50));
        pushButton->setStyleSheet(QString::fromUtf8("background: #F9F9F9;\n"
"\n"
"border: 5px solid #000000;\n"
"box-sizing: border-box;\n"
"border-radius: 24px;\n"
"font-family: Roboto;\n"
"font-style: normal;\n"
"font-weight: 900;\n"
"font-size: 24px;\n"
"line-height: 42px;\n"
"display: flex;\n"
"align-items: center;\n"
"text-align: center;\n"
"\n"
"color: #000000;\n"
""));

        horizontalLayout_6->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMinimumSize(QSize(225, 50));
        pushButton_2->setStyleSheet(QString::fromUtf8("background:  #000000;\n"
"border: 5px solid #000000;\n"
"box-sizing: border-box;\n"
"border-radius: 24px;\n"
"font-family: Roboto;\n"
"font-style: normal;\n"
"font-weight: 900;\n"
"font-size: 24px;\n"
"line-height: 42px;\n"
"display: flex;\n"
"align-items: center;\n"
"text-align: center;\n"
"\n"
"color: #F9F9F9;\n"
""));

        horizontalLayout_6->addWidget(pushButton_2);


        verticalLayout->addWidget(widget_3, 0, Qt::AlignHCenter);


        gridLayout->addWidget(verticalWidget, 2, 0, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(33);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 9, -1, 9);
        label_logo = new QLabel(centralwidget);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        sizePolicy1.setHeightForWidth(label_logo->sizePolicy().hasHeightForWidth());
        label_logo->setSizePolicy(sizePolicy1);
        label_logo->setMinimumSize(QSize(0, 0));
        label_logo->setLayoutDirection(Qt::LeftToRight);
        label_logo->setStyleSheet(QString::fromUtf8("position: absolute;\n"
"width: 1440px;\n"
"height: 319px;\n"
"left: 0px;\n"
"top: -117px;"));
        label_logo->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_2->addWidget(label_logo);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 2);

        LoginScreen->setCentralWidget(centralwidget);

        retranslateUi(LoginScreen);

        QMetaObject::connectSlotsByName(LoginScreen);
    } // setupUi

    void retranslateUi(QMainWindow *LoginScreen)
    {
        LoginScreen->setWindowTitle(QApplication::translate("LoginScreen", "LoginScreen", nullptr));
        label->setText(QApplication::translate("LoginScreen", "<html><head/><body><p><span style=\" font-size:54pt; font-weight:600;\">WELCOME!!!</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_user->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_user->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        lineEdit_user->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        lineEdit_user->setText(QString());
        lineEdit_user->setPlaceholderText(QApplication::translate("LoginScreen", "Username", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_pass->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineEdit_pass->setText(QString());
        lineEdit_pass->setPlaceholderText(QApplication::translate("LoginScreen", "Password", nullptr));
        pushButton->setText(QApplication::translate("LoginScreen", "SIGN IN", nullptr));
        pushButton_2->setText(QApplication::translate("LoginScreen", "SIGN UP", nullptr));
        label_logo->setText(QApplication::translate("LoginScreen", "<html><head/><body><p><img src=\":/resource/image/logo-removebg-preview (2).png\"/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginScreen: public Ui_LoginScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSCREEN_H
