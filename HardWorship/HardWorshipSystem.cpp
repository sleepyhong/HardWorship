#include "HardWorshipSystem.h"
#include "MainWindow.h"
#include "SlideWindow.h"
#include "LoginWindow.h"
#include "SignupWindow.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

/**
 *  Default Constructor
 */
CHardWorshipSystem::CHardWorshipSystem()
{
    mDatabase = QSqlDatabase::addDatabase("QMYSQL");
    mDatabase.setHostName("25.92.129.205");
    mDatabase.setPort(3306);
    mDatabase.setDatabaseName("hardworship");
    mDatabase.setUserName("hardworship");
    mDatabase.setPassword("Sm10230420?");

    mLoginWindow = nullptr;
    mSignupWindow = nullptr;
    mMainWindow = nullptr;
    mSlideWindow = nullptr;
}

/**
 *  Destructor
 */
CHardWorshipSystem::~CHardWorshipSystem()
{
    mDatabase.close();
    delete mLoginWindow;
    delete mSignupWindow;
    delete mMainWindow;
    delete mSlideWindow;
}
