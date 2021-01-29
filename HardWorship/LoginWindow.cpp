#include "LoginWindow.h"
#include "ui_loginwindow.h"
#include "MainWindow.h"
#include "SlideWindow.h"
#include "SignupWindow.h"

#include <QDebug>
#include <QRect>
#include <QWindow>
#include <QScreen>
#include <QCheckBox>
#include <QSqlQuery>
#include <QSqlError>

LoginWindow::LoginWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    mSystem = nullptr;
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

/**
 *  Save the password
 *  @param password
 */
void LoginWindow::on_PasswordLineEdit_textEdited(const QString &password)
{
    // Save the new password not containing sequences of *'s
    if (mPassword.length() < password.length())
    {
        mPassword += password.mid(mPassword.length());
    }
    else if (mPassword.length() > password.length())
    {
        mPassword = mPassword.mid(0, password.length());
    }

    // Show passwords according to whether checkbox is checked or not
    if (ui->ShowPasswordCheckBox->checkState() == 2)
    {
        ui->PasswordLineEdit->setText(mPassword);
    }
    else if (ui->ShowPasswordCheckBox->checkState() == 0)
    {
        QString hiddenPassword;
        for (int count = 0; count < mPassword.length(); ++count)
        {
            hiddenPassword += "*";
        }
        ui->PasswordLineEdit->setText(hiddenPassword);
    }
}

/**
 *  Logs in when the password to the username is correct
 */
void LoginWindow::on_SignInButton_clicked()
{
    if (!mSystem->GetDatabase().open())
    {
        ui->UserNameLineEdit->setText(mSystem->GetDatabase().lastError().text());
    }

    QString username = ui->UserNameLineEdit->text();

    // Checks whether the password to the given username is correct
    if (username != "" && mPassword != "")
    {
        bool exist = false;
        QSqlQuery query(mSystem->GetDatabase());
        query.exec("SELECT Username, Password FROM users");

        while(query.next())
        {
            if (query.value(0).toString() == username && query.value(1).toString() == mPassword)
            {
                mSystem->SetUsername(username);
                exist = true;
                break;
            }
        }
        if (exist)
        {
            mSystem->GetMainWindow()->show();
            QRect geometry = mSystem->GetMainWindow()->window()->windowHandle()->screen()->geometry();
            mSystem->GetMainWindow()->setGeometry(0, 50, geometry.width(), geometry.height());
            mSystem->GetMainWindow()->InitializeSongList();

            mSystem->GetSlideWindow()->show();
            this->close();
        }
    }
}

/**
 *  Opens SignupWindow to sign up
 */
void LoginWindow::on_SignUpButton_clicked()
{
    mSystem->GetSignupWindow()->show();
    this->close();
}

/**
 *  Show password if the checkbox is checked
 *  @param checked
 */
void LoginWindow::on_ShowPasswordCheckBox_clicked(bool checked)
{
    if (checked)
    {
        ui->PasswordLineEdit->setText(mPassword);
    }
    else
    {
        QString hiddenPassword;
        for (int count = 0; count < mPassword.length(); ++count)
        {
            hiddenPassword += "*";
        }
        ui->PasswordLineEdit->setText(hiddenPassword);
    }
}
