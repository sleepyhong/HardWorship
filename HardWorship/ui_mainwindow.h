/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <qsearchbar.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *SlideText;
    QLineEdit *SelectedSongListLineEdit;
    QLineEdit *LyricsLineEdit;
    QListWidget *SelectedSongList;
    QListWidget *LyricList;
    QSearchBar *SearchBar;
    QListWidget *SongList;
    QLabel *FontLabel;
    QFontComboBox *FontComboBox;
    QLabel *FontSizeLabel;
    QLineEdit *FontSizeLine;
    QLabel *MultiplierLabel;
    QLineEdit *MultiplierLine;
    QPushButton *BoldButton;
    QPushButton *ProjectButton;
    QListWidget *ImageList;
    QComboBox *LyricTypeComboBox;
    QLineEdit *OtherLyricTypeEdit;
    QSpinBox *LyricTypeNumberSpinBox;
    QPushButton *MoveLyricUpButton;
    QPushButton *MoveLyricDownButton;
    QTextEdit *LyricEdit;
    QLineEdit *NameBar;
    QPushButton *ChangeSongButton;
    QPushButton *NewSongButton;
    QPushButton *DeleteSongButton;
    QPushButton *AddSongButton;
    QPushButton *RemoveSongButton;
    QPushButton *AddLyricButton;
    QPushButton *DeleteLyricButton;
    QPushButton *ChangeLyricButton;
    QLabel *ErrorLabel;
    QLabel *SlideBackground;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(3000, 2000);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(3000, 2000));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SlideText = new QLabel(centralwidget);
        SlideText->setObjectName(QString::fromUtf8("SlideText"));
        SlideText->setGeometry(QRect(1340, 20, 1620, 1080));
        SlideText->setMaximumSize(QSize(1620, 1080));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferAntialias);
        SlideText->setFont(font);
        SlideText->setAlignment(Qt::AlignCenter);
        SelectedSongListLineEdit = new QLineEdit(centralwidget);
        SelectedSongListLineEdit->setObjectName(QString::fromUtf8("SelectedSongListLineEdit"));
        SelectedSongListLineEdit->setGeometry(QRect(30, 20, 500, 40));
        SelectedSongListLineEdit->setMaximumSize(QSize(500, 40));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        SelectedSongListLineEdit->setFont(font1);
        SelectedSongListLineEdit->setAutoFillBackground(false);
        SelectedSongListLineEdit->setAlignment(Qt::AlignCenter);
        SelectedSongListLineEdit->setReadOnly(true);
        LyricsLineEdit = new QLineEdit(centralwidget);
        LyricsLineEdit->setObjectName(QString::fromUtf8("LyricsLineEdit"));
        LyricsLineEdit->setGeometry(QRect(560, 22, 750, 40));
        LyricsLineEdit->setMaximumSize(QSize(750, 40));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        LyricsLineEdit->setFont(font2);
        LyricsLineEdit->setAlignment(Qt::AlignCenter);
        SelectedSongList = new QListWidget(centralwidget);
        SelectedSongList->setObjectName(QString::fromUtf8("SelectedSongList"));
        SelectedSongList->setGeometry(QRect(30, 70, 500, 400));
        SelectedSongList->setMaximumSize(QSize(500, 400));
        LyricList = new QListWidget(centralwidget);
        LyricList->setObjectName(QString::fromUtf8("LyricList"));
        LyricList->setGeometry(QRect(560, 70, 750, 1400));
        LyricList->setMaximumSize(QSize(750, 1400));
        SearchBar = new QSearchBar(centralwidget);
        SearchBar->setObjectName(QString::fromUtf8("SearchBar"));
        SearchBar->setGeometry(QRect(30, 480, 500, 40));
        SearchBar->setMaximumSize(QSize(500, 40));
        SearchBar->setAlignment(Qt::AlignCenter);
        SongList = new QListWidget(centralwidget);
        SongList->setObjectName(QString::fromUtf8("SongList"));
        SongList->setGeometry(QRect(30, 530, 500, 1200));
        SongList->setMaximumSize(QSize(500, 1200));
        FontLabel = new QLabel(centralwidget);
        FontLabel->setObjectName(QString::fromUtf8("FontLabel"));
        FontLabel->setGeometry(QRect(1340, 1120, 200, 40));
        FontLabel->setMaximumSize(QSize(200, 40));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        FontLabel->setFont(font3);
        FontLabel->setAlignment(Qt::AlignCenter);
        FontComboBox = new QFontComboBox(centralwidget);
        FontComboBox->setObjectName(QString::fromUtf8("FontComboBox"));
        FontComboBox->setGeometry(QRect(1550, 1120, 200, 40));
        FontComboBox->setMaximumSize(QSize(200, 40));
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setWeight(50);
        FontComboBox->setFont(font4);
        FontSizeLabel = new QLabel(centralwidget);
        FontSizeLabel->setObjectName(QString::fromUtf8("FontSizeLabel"));
        FontSizeLabel->setGeometry(QRect(1770, 1120, 200, 40));
        FontSizeLabel->setMaximumSize(QSize(200, 40));
        FontSizeLabel->setFont(font3);
        FontSizeLabel->setAlignment(Qt::AlignCenter);
        FontSizeLine = new QLineEdit(centralwidget);
        FontSizeLine->setObjectName(QString::fromUtf8("FontSizeLine"));
        FontSizeLine->setGeometry(QRect(1980, 1120, 200, 40));
        FontSizeLine->setMaximumSize(QSize(200, 40));
        FontSizeLine->setAlignment(Qt::AlignCenter);
        MultiplierLabel = new QLabel(centralwidget);
        MultiplierLabel->setObjectName(QString::fromUtf8("MultiplierLabel"));
        MultiplierLabel->setGeometry(QRect(2190, 1120, 40, 40));
        MultiplierLabel->setMaximumSize(QSize(40, 40));
        MultiplierLabel->setFont(font3);
        MultiplierLabel->setAlignment(Qt::AlignCenter);
        MultiplierLine = new QLineEdit(centralwidget);
        MultiplierLine->setObjectName(QString::fromUtf8("MultiplierLine"));
        MultiplierLine->setGeometry(QRect(2240, 1120, 200, 40));
        MultiplierLine->setMaximumSize(QSize(200, 40));
        MultiplierLine->setAlignment(Qt::AlignCenter);
        BoldButton = new QPushButton(centralwidget);
        BoldButton->setObjectName(QString::fromUtf8("BoldButton"));
        BoldButton->setGeometry(QRect(2800, 1120, 40, 40));
        BoldButton->setMaximumSize(QSize(40, 40));
        BoldButton->setFont(font3);
        ProjectButton = new QPushButton(centralwidget);
        ProjectButton->setObjectName(QString::fromUtf8("ProjectButton"));
        ProjectButton->setGeometry(QRect(2860, 1120, 100, 40));
        ProjectButton->setMaximumSize(QSize(100, 40));
        ImageList = new QListWidget(centralwidget);
        ImageList->setObjectName(QString::fromUtf8("ImageList"));
        ImageList->setGeometry(QRect(1340, 1170, 1620, 610));
        ImageList->setMaximumSize(QSize(1620, 610));
        ImageList->setFrameShadow(QFrame::Sunken);
        LyricTypeComboBox = new QComboBox(centralwidget);
        LyricTypeComboBox->addItem(QString());
        LyricTypeComboBox->addItem(QString());
        LyricTypeComboBox->addItem(QString());
        LyricTypeComboBox->addItem(QString());
        LyricTypeComboBox->addItem(QString());
        LyricTypeComboBox->setObjectName(QString::fromUtf8("LyricTypeComboBox"));
        LyricTypeComboBox->setGeometry(QRect(560, 1479, 200, 40));
        LyricTypeComboBox->setMaximumSize(QSize(200, 40));
        OtherLyricTypeEdit = new QLineEdit(centralwidget);
        OtherLyricTypeEdit->setObjectName(QString::fromUtf8("OtherLyricTypeEdit"));
        OtherLyricTypeEdit->setGeometry(QRect(770, 1480, 200, 40));
        OtherLyricTypeEdit->setMaximumSize(QSize(200, 40));
        OtherLyricTypeEdit->setReadOnly(true);
        LyricTypeNumberSpinBox = new QSpinBox(centralwidget);
        LyricTypeNumberSpinBox->setObjectName(QString::fromUtf8("LyricTypeNumberSpinBox"));
        LyricTypeNumberSpinBox->setGeometry(QRect(980, 1480, 50, 40));
        LyricTypeNumberSpinBox->setMaximumSize(QSize(50, 40));
        MoveLyricUpButton = new QPushButton(centralwidget);
        MoveLyricUpButton->setObjectName(QString::fromUtf8("MoveLyricUpButton"));
        MoveLyricUpButton->setGeometry(QRect(1220, 1480, 40, 40));
        MoveLyricUpButton->setMaximumSize(QSize(40, 40));
        MoveLyricDownButton = new QPushButton(centralwidget);
        MoveLyricDownButton->setObjectName(QString::fromUtf8("MoveLyricDownButton"));
        MoveLyricDownButton->setGeometry(QRect(1270, 1480, 40, 40));
        MoveLyricDownButton->setMaximumSize(QSize(40, 40));
        LyricEdit = new QTextEdit(centralwidget);
        LyricEdit->setObjectName(QString::fromUtf8("LyricEdit"));
        LyricEdit->setGeometry(QRect(560, 1530, 750, 250));
        LyricEdit->setMaximumSize(QSize(750, 250));
        NameBar = new QLineEdit(centralwidget);
        NameBar->setObjectName(QString::fromUtf8("NameBar"));
        NameBar->setGeometry(QRect(30, 1740, 390, 40));
        NameBar->setMaximumSize(QSize(390, 40));
        QFont font5;
        font5.setPointSize(9);
        NameBar->setFont(font5);
        ChangeSongButton = new QPushButton(centralwidget);
        ChangeSongButton->setObjectName(QString::fromUtf8("ChangeSongButton"));
        ChangeSongButton->setGeometry(QRect(430, 1740, 100, 40));
        ChangeSongButton->setMaximumSize(QSize(100, 40));
        NewSongButton = new QPushButton(centralwidget);
        NewSongButton->setObjectName(QString::fromUtf8("NewSongButton"));
        NewSongButton->setGeometry(QRect(30, 1790, 100, 40));
        NewSongButton->setMaximumSize(QSize(100, 40));
        DeleteSongButton = new QPushButton(centralwidget);
        DeleteSongButton->setObjectName(QString::fromUtf8("DeleteSongButton"));
        DeleteSongButton->setGeometry(QRect(140, 1790, 100, 40));
        DeleteSongButton->setMaximumSize(QSize(100, 40));
        AddSongButton = new QPushButton(centralwidget);
        AddSongButton->setObjectName(QString::fromUtf8("AddSongButton"));
        AddSongButton->setGeometry(QRect(320, 1790, 100, 40));
        AddSongButton->setMaximumSize(QSize(100, 40));
        RemoveSongButton = new QPushButton(centralwidget);
        RemoveSongButton->setObjectName(QString::fromUtf8("RemoveSongButton"));
        RemoveSongButton->setGeometry(QRect(430, 1790, 100, 40));
        RemoveSongButton->setMaximumSize(QSize(100, 40));
        AddLyricButton = new QPushButton(centralwidget);
        AddLyricButton->setObjectName(QString::fromUtf8("AddLyricButton"));
        AddLyricButton->setGeometry(QRect(560, 1790, 100, 40));
        AddLyricButton->setMaximumSize(QSize(100, 40));
        DeleteLyricButton = new QPushButton(centralwidget);
        DeleteLyricButton->setObjectName(QString::fromUtf8("DeleteLyricButton"));
        DeleteLyricButton->setGeometry(QRect(670, 1790, 100, 40));
        DeleteLyricButton->setMaximumSize(QSize(100, 40));
        ChangeLyricButton = new QPushButton(centralwidget);
        ChangeLyricButton->setObjectName(QString::fromUtf8("ChangeLyricButton"));
        ChangeLyricButton->setGeometry(QRect(1210, 1790, 100, 40));
        ChangeLyricButton->setMaximumSize(QSize(100, 40));
        ErrorLabel = new QLabel(centralwidget);
        ErrorLabel->setObjectName(QString::fromUtf8("ErrorLabel"));
        ErrorLabel->setGeometry(QRect(1340, 1790, 1620, 40));
        ErrorLabel->setMaximumSize(QSize(1620, 40));
        SlideBackground = new QLabel(centralwidget);
        SlideBackground->setObjectName(QString::fromUtf8("SlideBackground"));
        SlideBackground->setEnabled(true);
        SlideBackground->setGeometry(QRect(1340, 20, 1620, 1080));
        SlideBackground->setMaximumSize(QSize(1620, 1080));
        QFont font6;
        font6.setPointSize(24);
        font6.setBold(true);
        font6.setWeight(75);
        SlideBackground->setFont(font6);
        SlideBackground->setAutoFillBackground(false);
        SlideBackground->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        SongList->raise();
        SearchBar->raise();
        SelectedSongList->raise();
        NewSongButton->raise();
        RemoveSongButton->raise();
        DeleteSongButton->raise();
        AddSongButton->raise();
        NameBar->raise();
        ChangeSongButton->raise();
        SelectedSongListLineEdit->raise();
        LyricsLineEdit->raise();
        LyricList->raise();
        AddLyricButton->raise();
        DeleteLyricButton->raise();
        ChangeLyricButton->raise();
        LyricTypeComboBox->raise();
        LyricTypeNumberSpinBox->raise();
        OtherLyricTypeEdit->raise();
        SlideBackground->raise();
        ImageList->raise();
        ProjectButton->raise();
        FontComboBox->raise();
        FontLabel->raise();
        FontSizeLabel->raise();
        FontSizeLine->raise();
        MultiplierLabel->raise();
        MultiplierLine->raise();
        MoveLyricDownButton->raise();
        MoveLyricUpButton->raise();
        BoldButton->raise();
        ErrorLabel->raise();
        LyricEdit->raise();
        SlideText->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 3000, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SlideText->setText(QString());
        SelectedSongListLineEdit->setText(QCoreApplication::translate("MainWindow", "List of Selected Music", nullptr));
        LyricsLineEdit->setText(QCoreApplication::translate("MainWindow", "Lyrics", nullptr));
        SearchBar->setInputMask(QString());
        SearchBar->setText(QString());
        SearchBar->setPlaceholderText(QString());
        FontLabel->setText(QCoreApplication::translate("MainWindow", "Font-Style", nullptr));
        FontSizeLabel->setText(QCoreApplication::translate("MainWindow", "Font-Size", nullptr));
        FontSizeLine->setText(QCoreApplication::translate("MainWindow", "24", nullptr));
        MultiplierLabel->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        MultiplierLine->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        BoldButton->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        ProjectButton->setText(QCoreApplication::translate("MainWindow", "Project", nullptr));
        LyricTypeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Verse", nullptr));
        LyricTypeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Pre-Chorus", nullptr));
        LyricTypeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Chorus", nullptr));
        LyricTypeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Bridge", nullptr));
        LyricTypeComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Others", nullptr));

        MoveLyricUpButton->setText(QString());
        MoveLyricDownButton->setText(QString());
        ChangeSongButton->setText(QCoreApplication::translate("MainWindow", "Change", nullptr));
        NewSongButton->setText(QCoreApplication::translate("MainWindow", "New Song", nullptr));
        DeleteSongButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        AddSongButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        RemoveSongButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        AddLyricButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        DeleteLyricButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        ChangeLyricButton->setText(QCoreApplication::translate("MainWindow", "Change", nullptr));
        ErrorLabel->setText(QString());
        SlideBackground->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
