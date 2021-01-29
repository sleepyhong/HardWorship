#ifndef HARDWORSHIPSYSTEM_H
#define HARDWORSHIPSYSTEM_H

#include <QtSql>
#include <QSqlDatabase>

class LoginWindow;
class SignupWindow;
class MainWindow;
class SlideWindow;

class CHardWorshipSystem
{
public:
    CHardWorshipSystem();
    ~CHardWorshipSystem();

    /** Copy constructor disabled */
    CHardWorshipSystem(const CHardWorshipSystem&) = delete;
    /** Assignment Operator disabled */
    void operator=(const CHardWorshipSystem&) = delete;

    LoginWindow* GetLoginWindow() {return mLoginWindow;}
    void SetLoginWindow(LoginWindow* loginWindow){mLoginWindow = loginWindow;}

    SignupWindow* GetSignupWindow() {return mSignupWindow;}
    void SetSignupWindow(SignupWindow* signupWindow){mSignupWindow = signupWindow;}

    MainWindow* GetMainWindow() {return mMainWindow;}
    void SetMainWindow(MainWindow* mainWindow){mMainWindow = mainWindow;}

    SlideWindow* GetSlideWindow() {return mSlideWindow;}
    void SetSlideWindow(SlideWindow* slideWindow){mSlideWindow = slideWindow;}

    QSqlDatabase GetDatabase() {return mDatabase;}
    void SetDatabase(QSqlDatabase database) {mDatabase = database;}

    QString GetUsername() {return mUsername;}
    void SetUsername(QString username) {mUsername = username;}


private:
    LoginWindow* mLoginWindow;          // login window
    SignupWindow* mSignupWindow;        // signup window
    MainWindow* mMainWindow;            // main window
    SlideWindow* mSlideWindow;          // slide window

    QSqlDatabase mDatabase;
    QString mUsername;
};

#endif // HARDWORSHIPSYSTEM_H
