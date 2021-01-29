#include "SignupWindow.h"
#include "ui_signupwindow.h"
#include "LoginWindow.h"

#include <QDebug>
#include <QString>
#include <QSqlQuery>

/**
 *  Constructor
 *  @param parent
 */
SignupWindow::SignupWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::SignupWindow)
{
    ui->setupUi(this);
    mSystem = nullptr;

    mValidUsername = true;
    mValidPassword = false;
}

/**
 *  Destructor
 */
SignupWindow::~SignupWindow()
{
    delete ui;
}

/**
 *  Check if the input username is unique and other users do not have it
 *  @param newUsername
 */
void SignupWindow::on_UsernameLineEdit_textEdited(const QString &username)
{
    if (mSystem != nullptr)
    {
        mValidUsername = true;

        QSqlQuery query(mSystem->GetDatabase());
        query.exec("SELECT Username FROM users");

        // Check whether input username is an unique username
        while(query.next())
        {
            if (username == query.value(0).toString())
            {
                mValidUsername = false;
                break;
            }
        }
    }
    else
    {
        qDebug() << "System has not been assigned";
    }
}

/**
 *  Confirm second password is same as first password
 *  @param password
 */
void SignupWindow::on_ConfirmPasswordLineEdit_textEdited(const QString &password)
{
    if (ui->PasswordLineEdit->text() == password)
    {
        mValidPassword = true;
    }
    else
    {
        mValidPassword = false;
    }
}

/**
 *  Checks if the input email is unique and there is no account made with it
 *  @param email
 */
void SignupWindow::on_EmailLineEdit_textEdited(const QString &email)
{
    if (mSystem != nullptr)
    {
        mValidEmail = true;

        QSqlQuery query(mSystem->GetDatabase());
        query.exec("SELECT Email FROM users");

        while(query.next())
        {
            if (email == query.value(0).toString())
            {
                mValidEmail = false;
                break;
            }
        }
    }
    else
    {
        qDebug() << "System has not been assigned";
    }
}

/**
 *  Creates an account when all requirements are met
 */
void SignupWindow::on_SignupButton_clicked()
{
    if (ui->UsernameLineEdit->text() == "")
    {
        ui->ErrorLabel->setText("Please enter your username");
    }
    else if (ui->PasswordLineEdit->text() == "")
    {
        ui->ErrorLabel->setText("Please enter your password");
    }
    else if (ui->FirstNameLineEdit->text() == "")
    {
       ui->ErrorLabel ->setText("Please enter your first name");
    }
    else if (ui->LastNameLineEdit->text() == "")
    {
        ui->ErrorLabel->setText("Please enter your last name");
    }
    else if (ui->EmailLineEdit->text() == "")
    {
        ui->ErrorLabel->setText("Please enter your email");
    }
    else
    {
        if (!mValidUsername)
        {
            ui->ErrorLabel->setText("This username already exists");
        }
        else if(!mValidPassword)
        {
            ui->ErrorLabel->setText("The passwords entered in Password and Confirm Password do not match");
        }
        else if(!mValidEmail)
        {
            ui->ErrorLabel->setText("This email already has an account");
        }
        else
        {
            ui->ErrorLabel->setText("");
        }
    }

    if (mValidUsername && mValidPassword && mValidEmail &&
            ui->FirstNameLineEdit->text() != "" &&
            ui->LastNameLineEdit->text() != "" &&
            ui->UsernameLineEdit->text() != "" &&
            ui->PasswordLineEdit->text() != "" &&
            ui->EmailLineEdit->text() != "")
    {
        ui->ErrorLabel->setText("");

        QSqlQuery query(mSystem->GetDatabase());
        query.prepare("INSERT INTO users (Username, Password, FirstName, MiddleName, LastName, Email) "
                   "VALUES (:Username, :Password, :FirstName, :MiddleName, :LastName, :Email)");
        query.bindValue(":Username", ui->UsernameLineEdit->text());
        query.bindValue(":Password", ui->PasswordLineEdit->text());
        query.bindValue(":FirstName", ui->FirstNameLineEdit->text());
        query.bindValue(":MiddleName", ui->MiddleNameLineEdit->text());
        query.bindValue(":LastName", ui->LastNameLineEdit->text());
        query.bindValue(":Email", ui->EmailLineEdit->text());
        query.exec();

        mSystem->GetLoginWindow()->show();
        this->close();

        query.exec("CREATE TABLE " + ui->UsernameLineEdit->text().toLower() + "(MusicTitle VARCHAR(100) NOT NULL, MusicXML TEXT)");
    }
}
