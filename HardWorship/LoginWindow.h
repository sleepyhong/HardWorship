#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "HardWorshipSystem.h"

#include <QMainWindow>

#include <memory>

namespace Ui { class LoginWindow; }

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

    std::shared_ptr<CHardWorshipSystem> GetSystem() {return mSystem;}
    void SetSystem(std::shared_ptr<CHardWorshipSystem> system)
    {
        mSystem = system;
        system->SetLoginWindow(this);
    }

private slots:
    void on_PasswordLineEdit_textEdited(const QString &password);
    void on_SignInButton_clicked();
    void on_SignUpButton_clicked();

    void on_ShowPasswordCheckBox_clicked(bool checked);

private:
    Ui::LoginWindow *ui;
    std::shared_ptr<CHardWorshipSystem> mSystem;
    QString mPassword;
};

#endif // LOGINWINDOW_H
