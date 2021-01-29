/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QPushButton *SignInButton;
    QLineEdit *UserNameLineEdit;
    QLineEdit *PasswordLineEdit;
    QLabel *SignInLabel;
    QLabel *UsernameLabel;
    QLabel *PasswordLabel;
    QPushButton *SignUpButton;
    QCheckBox *ShowPasswordCheckBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(800, 485);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SignInButton = new QPushButton(centralwidget);
        SignInButton->setObjectName(QString::fromUtf8("SignInButton"));
        SignInButton->setGeometry(QRect(40, 370, 381, 51));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        SignInButton->setFont(font);
        UserNameLineEdit = new QLineEdit(centralwidget);
        UserNameLineEdit->setObjectName(QString::fromUtf8("UserNameLineEdit"));
        UserNameLineEdit->setGeometry(QRect(40, 160, 600, 51));
        QFont font1;
        font1.setPointSize(9);
        UserNameLineEdit->setFont(font1);
        PasswordLineEdit = new QLineEdit(centralwidget);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));
        PasswordLineEdit->setGeometry(QRect(40, 280, 600, 51));
        PasswordLineEdit->setFont(font1);
        SignInLabel = new QLabel(centralwidget);
        SignInLabel->setObjectName(QString::fromUtf8("SignInLabel"));
        SignInLabel->setGeometry(QRect(100, 20, 600, 71));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        SignInLabel->setFont(font2);
        SignInLabel->setAlignment(Qt::AlignCenter);
        UsernameLabel = new QLabel(centralwidget);
        UsernameLabel->setObjectName(QString::fromUtf8("UsernameLabel"));
        UsernameLabel->setGeometry(QRect(40, 110, 171, 31));
        UsernameLabel->setFont(font);
        PasswordLabel = new QLabel(centralwidget);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));
        PasswordLabel->setGeometry(QRect(40, 230, 171, 31));
        PasswordLabel->setFont(font);
        SignUpButton = new QPushButton(centralwidget);
        SignUpButton->setObjectName(QString::fromUtf8("SignUpButton"));
        SignUpButton->setGeometry(QRect(460, 370, 181, 51));
        SignUpButton->setFont(font);
        ShowPasswordCheckBox = new QCheckBox(centralwidget);
        ShowPasswordCheckBox->setObjectName(QString::fromUtf8("ShowPasswordCheckBox"));
        ShowPasswordCheckBox->setGeometry(QRect(660, 280, 111, 51));
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        SignInButton->setText(QCoreApplication::translate("LoginWindow", "Log in", nullptr));
        SignInLabel->setText(QCoreApplication::translate("LoginWindow", "Sign In", nullptr));
        UsernameLabel->setText(QCoreApplication::translate("LoginWindow", "Username", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        SignUpButton->setText(QCoreApplication::translate("LoginWindow", "Sign up", nullptr));
        ShowPasswordCheckBox->setText(QCoreApplication::translate("LoginWindow", "Show Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
