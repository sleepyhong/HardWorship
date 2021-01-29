#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include "HardWorshipSystem.h"

#include <QMainWindow>
#include <QString>

#include <vector>
#include <memory>

class CHardWorshipSystem;

namespace Ui { class SignupWindow; }

class SignupWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignupWindow(QWidget *parent = nullptr);
    ~SignupWindow();

    std::shared_ptr<CHardWorshipSystem> GetSystem() {return mSystem;}
    void SetSystem(std::shared_ptr<CHardWorshipSystem> system)
    {
        mSystem = system;
        system->SetSignupWindow(this);
    }

private slots:
    void on_UsernameLineEdit_textEdited(const QString &username);
    void on_ConfirmPasswordLineEdit_textEdited(const QString &password);
    void on_EmailLineEdit_textEdited(const QString &email);
    void on_SignupButton_clicked();

private:
    Ui::SignupWindow *ui;
    std::shared_ptr<CHardWorshipSystem> mSystem;

    bool mValidUsername;
    bool mValidPassword;
    bool mValidEmail;
};

#endif // SIGNUPWINDOW_H
