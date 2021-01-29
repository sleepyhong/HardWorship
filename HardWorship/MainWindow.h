#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Song.h"
#include "SlideWindow.h"
#include "HardWorshipSystem.h"

#include <QMainWindow>
#include <QString>
#include <QListWidget>
#include <QListWidgetItem>
#include <QCloseEvent>

#include <vector>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow* GetUi() {return ui;}
    void SetUi(Ui::MainWindow* newUi) {ui = newUi;}

    std::vector<QString> GetSongTitles() {return mSongTitles;}
    void AddSongTitle(QString title) {mSongTitles.push_back(title);}

    std::shared_ptr<SlideWindow> GetSlideWindow() {return mSlideWindow;}
    void SetSlideWindow(std::shared_ptr<SlideWindow> slideWindow)
    {
        mSlideWindow = slideWindow;
        mSlideWindow->SetMainWindow(this);
    }

    QString GetDirectory() {return mDirectory;}
    void SetDirectory(QString directory) {mDirectory = directory;}

    bool GetIsBold() {return mIsBold;}
    void SetIsBold(bool bold) {mIsBold = bold;}

    std::shared_ptr<CHardWorshipSystem> GetSystem() {return mSystem;}
    void SetSystem(std::shared_ptr<CHardWorshipSystem> system)
    {
        mSystem = system;
        system->SetMainWindow(this);
    }

    void InitializeSongList();

private:
    void InitializeImageList();
    void InitializeSearchBarText();

    void UpdateLyrics();
    void UpdateSlideLyric();

    void resizeEvent(QResizeEvent* event);

private slots:
    void on_SearchBar_textEdited(const QString &songTitle);
    void RemoveInitialText();

    void on_NewSongButton_clicked();
    void on_DeleteSongButton_clicked();
    void on_AddSongButton_clicked();
    void on_RemoveSongButton_clicked();

    void on_SongList_itemClicked(QListWidgetItem *item);
    void on_ChangeSongButton_clicked();

    void on_SelectedSongList_itemClicked(QListWidgetItem *item);
    void on_LyricList_itemClicked(QListWidgetItem *item);
    void on_AddLyricButton_clicked();
    void on_DeleteLyricButton_clicked();
    void on_ChangeLyricButton_clicked();
    void on_LyricTypeComboBox_currentIndexChanged(int index);
    void on_MoveLyricUpButton_clicked();
    void on_MoveLyricDownButton_clicked();

    void on_ImageList_itemClicked(QListWidgetItem *item);

    void on_FontComboBox_currentFontChanged(const QFont &fontStyle);
    void on_FontSizeLine_textChanged(const QString &fontSize);

    void on_ProjectButton_clicked();
    void on_BoldButton_clicked();

    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;                                 // ui of mainwindow

    std::shared_ptr<SlideWindow> mSlideWindow;          // window that presenets lyrics and background images

    std::vector<QString> mSongTitles;                   // list of song titles
    std::vector<CSong*> mSelectedSongs;                 // list of selected songs (within SelectedSongList)

    QString mDirectory;                                 // current path of directory

    bool mIsBold = true;                                // boolean whether text should be bold or not in SlideText widget

    std::shared_ptr<CHardWorshipSystem> mSystem;
};
#endif // MAINWINDOW_H
