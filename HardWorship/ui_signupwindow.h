/********************************************************************************
** Form generated from reading UI file 'signupwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignupWindow
{
public:
    QWidget *centralwidget;
    QLabel *SignupLabel;
    QLineEdit *UsernameLineEdit;
    QLabel *UsernameLabel;
    QLabel *PasswordLabel;
    QLineEdit *PasswordLineEdit;
    QLabel *ConfirmPasswordLabel;
    QLineEdit *ConfirmPasswordLineEdit;
    QLabel *FirstNameLabel;
    QLineEdit *FirstNameLineEdit;
    QLabel *MiddleNameLabel;
    QLineEdit *MiddleNameLineEdit;
    QLabel *LastNameLabel;
    QLineEdit *LastNameLineEdit;
    QLabel *EmailLabel;
    QLineEdit *EmailLineEdit;
    QPushButton *SignupButton;
    QLabel *ErrorLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SignupWindow)
    {
        if (SignupWindow->objectName().isEmpty())
            SignupWindow->setObjectName(QString::fromUtf8("SignupWindow"));
        SignupWindow->resize(1050, 900);
        QFont font;
        font.setPointSize(9);
        SignupWindow->setFont(font);
        centralwidget = new QWidget(SignupWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SignupLabel = new QLabel(centralwidget);
        SignupLabel->setObjectName(QString::fromUtf8("SignupLabel"));
        SignupLabel->setGeometry(QRect(175, 20, 601, 91));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        SignupLabel->setFont(font1);
        SignupLabel->setAlignment(Qt::AlignCenter);
        UsernameLineEdit = new QLineEdit(centralwidget);
        UsernameLineEdit->setObjectName(QString::fromUtf8("UsernameLineEdit"));
        UsernameLineEdit->setGeometry(QRect(20, 160, 1010, 41));
        UsernameLabel = new QLabel(centralwidget);
        UsernameLabel->setObjectName(QString::fromUtf8("UsernameLabel"));
        UsernameLabel->setGeometry(QRect(20, 123, 331, 31));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        UsernameLabel->setFont(font2);
        PasswordLabel = new QLabel(centralwidget);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));
        PasswordLabel->setGeometry(QRect(20, 210, 331, 31));
        PasswordLabel->setFont(font2);
        PasswordLineEdit = new QLineEdit(centralwidget);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));
        PasswordLineEdit->setGeometry(QRect(20, 250, 1010, 41));
        ConfirmPasswordLabel = new QLabel(centralwidget);
        ConfirmPasswordLabel->setObjectName(QString::fromUtf8("ConfirmPasswordLabel"));
        ConfirmPasswordLabel->setGeometry(QRect(20, 300, 331, 31));
        ConfirmPasswordLabel->setFont(font2);
        ConfirmPasswordLineEdit = new QLineEdit(centralwidget);
        ConfirmPasswordLineEdit->setObjectName(QString::fromUtf8("ConfirmPasswordLineEdit"));
        ConfirmPasswordLineEdit->setGeometry(QRect(20, 340, 1010, 41));
        FirstNameLabel = new QLabel(centralwidget);
        FirstNameLabel->setObjectName(QString::fromUtf8("FirstNameLabel"));
        FirstNameLabel->setGeometry(QRect(20, 410, 331, 31));
        FirstNameLabel->setFont(font2);
        FirstNameLineEdit = new QLineEdit(centralwidget);
        FirstNameLineEdit->setObjectName(QString::fromUtf8("FirstNameLineEdit"));
        FirstNameLineEdit->setGeometry(QRect(20, 450, 1010, 41));
        MiddleNameLabel = new QLabel(centralwidget);
        MiddleNameLabel->setObjectName(QString::fromUtf8("MiddleNameLabel"));
        MiddleNameLabel->setGeometry(QRect(20, 500, 331, 31));
        MiddleNameLabel->setFont(font2);
        MiddleNameLineEdit = new QLineEdit(centralwidget);
        MiddleNameLineEdit->setObjectName(QString::fromUtf8("MiddleNameLineEdit"));
        MiddleNameLineEdit->setGeometry(QRect(20, 540, 1010, 41));
        LastNameLabel = new QLabel(centralwidget);
        LastNameLabel->setObjectName(QString::fromUtf8("LastNameLabel"));
        LastNameLabel->setGeometry(QRect(20, 590, 331, 31));
        LastNameLabel->setFont(font2);
        LastNameLineEdit = new QLineEdit(centralwidget);
        LastNameLineEdit->setObjectName(QString::fromUtf8("LastNameLineEdit"));
        LastNameLineEdit->setGeometry(QRect(20, 630, 1010, 41));
        EmailLabel = new QLabel(centralwidget);
        EmailLabel->setObjectName(QString::fromUtf8("EmailLabel"));
        EmailLabel->setGeometry(QRect(20, 680, 331, 31));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        EmailLabel->setFont(font3);
        EmailLineEdit = new QLineEdit(centralwidget);
        EmailLineEdit->setObjectName(QString::fromUtf8("EmailLineEdit"));
        EmailLineEdit->setGeometry(QRect(20, 720, 1010, 41));
        SignupButton = new QPushButton(centralwidget);
        SignupButton->setObjectName(QString::fromUtf8("SignupButton"));
        SignupButton->setGeometry(QRect(839, 791, 161, 41));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(true);
        font4.setWeight(75);
        SignupButton->setFont(font4);
        ErrorLabel = new QLabel(centralwidget);
        ErrorLabel->setObjectName(QString::fromUtf8("ErrorLabel"));
        ErrorLabel->setGeometry(QRect(20, 790, 801, 41));
        SignupWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SignupWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1050, 21));
        SignupWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SignupWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SignupWindow->setStatusBar(statusbar);

        retranslateUi(SignupWindow);

        QMetaObject::connectSlotsByName(SignupWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SignupWindow)
    {
        SignupWindow->setWindowTitle(QCoreApplication::translate("SignupWindow", "MainWindow", nullptr));
        SignupLabel->setText(QCoreApplication::translate("SignupWindow", "Sign Up", nullptr));
        UsernameLabel->setText(QCoreApplication::translate("SignupWindow", "Username", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("SignupWindow", "Password", nullptr));
        ConfirmPasswordLabel->setText(QCoreApplication::translate("SignupWindow", "Confirm Password", nullptr));
        FirstNameLabel->setText(QCoreApplication::translate("SignupWindow", "First Name", nullptr));
        MiddleNameLabel->setText(QCoreApplication::translate("SignupWindow", "Middle Name", nullptr));
        LastNameLabel->setText(QCoreApplication::translate("SignupWindow", "Last Name", nullptr));
        EmailLabel->setText(QCoreApplication::translate("SignupWindow", "Email", nullptr));
        SignupButton->setText(QCoreApplication::translate("SignupWindow", "Sign up", nullptr));
        ErrorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SignupWindow: public Ui_SignupWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H
