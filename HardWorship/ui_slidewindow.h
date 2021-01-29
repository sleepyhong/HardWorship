/********************************************************************************
** Form generated from reading UI file 'slidewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDEWINDOW_H
#define UI_SLIDEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SlideWindow
{
public:
    QWidget *centralwidget;
    QPushButton *FullScreenButton;
    QLabel *LyricLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SlideWindow)
    {
        if (SlideWindow->objectName().isEmpty())
            SlideWindow->setObjectName(QString::fromUtf8("SlideWindow"));
        SlideWindow->resize(1920, 1080);
        centralwidget = new QWidget(SlideWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FullScreenButton = new QPushButton(centralwidget);
        FullScreenButton->setObjectName(QString::fromUtf8("FullScreenButton"));
        FullScreenButton->setGeometry(QRect(30, 30, 150, 40));
        LyricLabel = new QLabel(centralwidget);
        LyricLabel->setObjectName(QString::fromUtf8("LyricLabel"));
        LyricLabel->setGeometry(QRect(0, 0, 1920, 1080));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        LyricLabel->setFont(font);
        LyricLabel->setAlignment(Qt::AlignCenter);
        SlideWindow->setCentralWidget(centralwidget);
        LyricLabel->raise();
        FullScreenButton->raise();
        menubar = new QMenuBar(SlideWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 21));
        SlideWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SlideWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SlideWindow->setStatusBar(statusbar);

        retranslateUi(SlideWindow);

        QMetaObject::connectSlotsByName(SlideWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SlideWindow)
    {
        SlideWindow->setWindowTitle(QCoreApplication::translate("SlideWindow", "MainWindow", nullptr));
        FullScreenButton->setText(QCoreApplication::translate("SlideWindow", "FullScreen", nullptr));
        LyricLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SlideWindow: public Ui_SlideWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDEWINDOW_H
