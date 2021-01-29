#include "MainWindow.h"
#include "SlideWindow.h"
#include "LoginWindow.h"
#include "SignupWindow.h"
#include "Song.h"
#include "HardWorshipSystem.h"

#include <QApplication>
#include <QCoreApplication>

#include <memory>

using namespace std;

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    QApplication a(argc, argv);

    shared_ptr<CHardWorshipSystem> system (new CHardWorshipSystem());

    // Initialize MainWindow
    MainWindow* mainWindow = new MainWindow();

    // Initialize SlideWindow
    shared_ptr<SlideWindow> slideWindow = make_shared<SlideWindow>(new SlideWindow());
    mainWindow->SetSlideWindow(slideWindow);

    // Initialize LoginWindow
    LoginWindow* loginWindow = new LoginWindow();
    // Initialize SignupWindow
    SignupWindow* signupWindow = new SignupWindow();

    mainWindow->SetSystem(system);
    slideWindow->SetSystem(system);
    loginWindow->SetSystem(system);
    signupWindow->SetSystem(system);

    loginWindow->show();

    return a.exec();

}
