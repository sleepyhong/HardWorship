#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <QtXml>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QPixmap>
#include <QGraphicsDropShadowEffect>
#include <QIcon>
#include <QDir>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
#include <QDomNodeList>
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

#include <memory>
#include <algorithm>
#include <math.h>

using namespace std;

/**
 *  Constructor
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mSystem = nullptr;

    mDirectory = QDir::currentPath();
    mDirectory = mDirectory.replace("\"", "/", Qt::CaseInsensitive);

    InitializeImageList();

    // Initialize SearchBarText widget
    InitializeSearchBarText();
    connect(ui->SearchBar, SIGNAL(focussed()), this, SLOT(RemoveInitialText()));
    connect(ui->SearchBar, SIGNAL(unfocussed()), this, SLOT(InitializeSearchBarText()));

    // Initialize Buttons that changes order of lyrics
    QPixmap downButton(mDirectory + "/images/down_button.png");
    QIcon downButtonIcon(downButton);
    ui->MoveLyricDownButton->setIcon(downButtonIcon);
    QPixmap upButton(mDirectory + "/images/up_button.png");
    QIcon upButtonIcon(upButton);
    ui->MoveLyricUpButton->setIcon(upButtonIcon);

    // Initialize default color (gray) of OtherLyricTypeEdit widget
    ui->OtherLyricTypeEdit->setStyleSheet("QLineEdit {background: #AAAAAA;}");

    // Initialize SlideText Text Setting
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(10);
    effect->setColor(QColor("#000000"));
    effect->setOffset(1,1);
    ui->SlideText->setGraphicsEffect(effect);
    ui->SlideText->setStyleSheet("QLabel { color : white; }");

    // Enable BoldButton to change its background color
    ui->BoldButton->setAutoFillBackground(true);
}

/**
 *  Destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
    for (auto song : mSelectedSongs)
    {
        delete song;
    }
}

/**
 *  Initialize the list of saved/pre-existing songs from List.txt
 */
void MainWindow::InitializeSongList()
{
    if (mSystem != nullptr)
    {
        QSqlQuery query(mSystem->GetDatabase());
        if (query.exec("SELECT MusicTitle, MusicXML FROM " + mSystem->GetUsername()))
        {
            // Read each title of the song and save them in the mSongTitles
            while (query.next())
            {
                QString musicTitle = query.value(0).toString();

                AddSongTitle(musicTitle);
                QFile file(mDirectory + "/songs/" + musicTitle + ".xml");
                file.resize(0);
                if(file.open(QFile::ReadWrite | QFile::Text))
                {
                    QTextStream out(&file);
                    out << query.value(1).toString();
                    file.close();
                }
            }

            // Sorts mSongTitles in alphabetical order
            sort(mSongTitles.begin(), mSongTitles.end());

            // Add each song titles to SongList QListWidget
            for (size_t cnt = 0; cnt < mSongTitles.size(); ++cnt)
            {
                ui->SongList->addItem(mSongTitles[cnt]);
            }
        }
        else
        {
            ui->ErrorLabel->setText(query.lastError().text());
        }
    }
    else
    {
        qDebug() << "A system has not been assigned";
    }
}

/**
 *  Initialize the list of background images
 */
void MainWindow::InitializeImageList()
{
    ui->ImageList->setViewMode(QListWidget::IconMode);
    ui->ImageList->setIconSize(QSize(200, 150));
    ui->ImageList->setResizeMode(QListWidget::Adjust);

    // Counts how many background images there are from TotalIamges.txt
    int cnt = 0;
    QFile file(mDirectory + "/background_images/TotalImages.txt");
    if(file.open(QFile::ReadWrite | QFile::Text))
    {
        QTextStream total(&file);
        cnt = total.readLine().toInt();
        file.close();
    }

    // Add each background images with its name to ImageList
    for (int num = 0; num < cnt; ++num)
    {
        QString path = mDirectory + "/background_images/background_";
        if (num == 0)
        {
            path += "default.jpg";
            QListWidgetItem *item = new QListWidgetItem(QIcon(path), QString("background_default.jpg"));
            ui->ImageList->addItem(item);
        }
        else
        {
            path += QString::number(num) + ".jpg";
            QListWidgetItem *item = new QListWidgetItem(QIcon(path), QString("background_" + QString::number(num) + ".jpg"));
            ui->ImageList->addItem(item);
        }
    }
}

/**
 *  Re-initialize "Search title of music"
 */
void MainWindow::InitializeSearchBarText()
{
    if (ui->SearchBar->text() == "")
    {
        ui->SearchBar->setText("Search title of music");
    }
}

/**
 * Updates lyrics of selected song
 */
void MainWindow::UpdateLyrics()
{
    if (ui->SelectedSongList->currentItem() != nullptr)
    {
        // Opens selected song text file and edit lyrics
        QFile file(mDirectory + "/songs/" + ui->SelectedSongList->currentItem()->text() + ".xml");
        QDomDocument song;
        if (file.open(QFile::WriteOnly | QFile::Text))
        {
            song.setContent(&file);
            QDomElement root = song.documentElement();

            // Clear all elements in the file
            // Clear all elements in the file
            QDomNodeList rootChildren = root.childNodes();      // child nodes of root
            for (int count = 0; count < rootChildren.count(); ++count)
            {
                // Removes all lyric elements
                QDomNodeList rootGrandChildren = rootChildren.at(count).childNodes();
                for (int num = 0; num < rootGrandChildren.count(); ++num)
                {
                    rootGrandChildren.at(num).clear();
                }

                // Removes child of root such as verse, prechorus, chorus, or bridge
                rootChildren.at(count).clear();
            }

            QTextStream out(&file);
            // Insert head of the xml file
            out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
            // root of the xml file
            out << "<song>\n";

            // Access each widget item in LyricList
            for (int row = 0; row < ui->LyricList->count(); ++row)
            {
                QString lyric = ui->LyricList->item(row)->text();

                // Make sure there is right number of \n's
                for (int cnt = lyric.length() - 1; cnt > 0; --cnt)
                {
                    // second to last = \n and last = \n -> remove last \n
                    if (lyric.mid(lyric.length() - 2, 1) == "\n"
                            && lyric.mid(lyric.length() - 1) == "\n")
                    {
                        lyric = lyric.mid(0, lyric.length() - 1);
                    }
                    // second to last != \n and last =\n -> done!
                    else if (lyric.mid(lyric.length() - 2, 1) != "\n"
                             && lyric.mid(lyric.length() - 1) == "\n")
                    {
                        break;
                    }
                    // second to last != \n and last != \n -> add \n at the end of lyric
                    else if (lyric.mid(lyric.length() - 2, 1) != "\n"
                             && lyric.mid(lyric.length() - 1) != "\n")
                    {
                        lyric = lyric + "\n";
                    }
                }
                ui->LyricList->item(row)->setText(lyric);

                QString lyricType;
                int indexOfNewLine = 0;

                for (int count = 1; count <= lyric.count("\n"); ++count)
                {
                    // Insert lyric type element
                    if (count == 1)
                    {
                        indexOfNewLine = lyric.indexOf("\n");
                        int indexOfSpace = lyric.indexOf(" ");

                        out << "\t<";
                        if (indexOfNewLine - indexOfSpace > 1)
                        {
                            lyricType = lyric.mid(0, indexOfSpace).toLower();
                            out << lyricType +
                                   " num = \"" +
                                   lyric.mid(indexOfSpace + 1, indexOfNewLine - (indexOfSpace + 1)) +
                                   "\">\n";
                        }
                        else
                        {
                            lyricType = lyric.mid(0, indexOfNewLine - 1).toLower();
                            out << lyricType + ">\n";
                        }
                    }
                    // Insert lyric element
                    else
                    {
                        int prevIndexOfNewLine = indexOfNewLine;
                        indexOfNewLine = lyric.indexOf("\n", prevIndexOfNewLine + 1);

                        out << "\t\t<lyric>" +
                               lyric.mid(prevIndexOfNewLine + 1, indexOfNewLine - (prevIndexOfNewLine + 1)) +
                               "</lyric>\n";
                        if (count == lyric.count("\n"))
                        {
                            out << "\t</" + lyricType + ">\n";
                        }
                    }

                }
            }

            out << "</song>";
            file.close();

            if (file.open(QFile::ReadOnly | QFile::Text))
            {
                QTextStream in(&file);
                QString xml = in.readAll().replace("'", "\\'");
                // Saves the changes made in the database
                QSqlQuery query(mSystem->GetDatabase());
                if (!query.exec("UPDATE " + mSystem->GetUsername() +
                                " SET MusicXML = \'" + xml +
                                "\' WHERE MusicTitle = \'" + ui->SelectedSongList->currentItem()->text() + "\'"))
                {
                    ui->ErrorLabel->setText(query.lastError().text());
                }
                file.close();
            }

            // Save changes in song class
            for (size_t cnt = 0; cnt < mSelectedSongs.size(); ++cnt)
            {
                if (mSelectedSongs[cnt]->GetName() == ui->SelectedSongList->currentItem()->text())
                {
                    mSelectedSongs[cnt]->InitializeLyrics();
                }
            }
        }
    }
}

/**
 *  Sets the lyric that slide will contain
 */
void MainWindow::UpdateSlideLyric()
{
    QString lyric = ui->LyricList->currentItem()->text();

    // Ignores first line - lyric type - of lyric
    int index = lyric.indexOf("\n") + 1;
    lyric = ui->LyricList->currentItem()->text().mid(index);

    // Ignores last empty line
    ui->SlideText->setText(lyric.mid(0, lyric.length() - 1));
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    double heightPercent = (double)this->height() / (double)this->maximumHeight();
    double widthPercent = (double)this->width() / (double)this->maximumWidth();

    ui->SelectedSongListLineEdit->setGeometry(30 * widthPercent,
                                              20 * heightPercent,
                                              ui->SelectedSongListLineEdit->maximumWidth() * widthPercent,
                                              ui->SelectedSongListLineEdit->maximumHeight() * heightPercent);
    ui->SelectedSongList->setGeometry(30 * widthPercent,
                                      70 * heightPercent,
                                      ui->SelectedSongList->maximumWidth() * widthPercent,
                                      ui->SelectedSongList->maximumHeight() * heightPercent);
    ui->SearchBar->setGeometry(30 * widthPercent,
                               480 * heightPercent,
                               ui->SearchBar->maximumWidth() * widthPercent,
                               ui->SearchBar->maximumHeight() * heightPercent);
    ui->SongList->setGeometry(30 * widthPercent,
                              530 * heightPercent,
                              ui->SongList->maximumWidth() * widthPercent,
                              ui->SongList->maximumHeight() * heightPercent);
    ui->NameBar->setGeometry(30 * widthPercent,
                             1740 * heightPercent,
                             ui->NameBar->maximumWidth() * widthPercent,
                             ui->NameBar->maximumHeight() * heightPercent);
    ui->ChangeSongButton->setGeometry(430 * widthPercent,
                                      1740 * heightPercent,
                                      ui->ChangeSongButton->maximumWidth() * widthPercent,
                                      ui->ChangeSongButton->maximumHeight() * heightPercent);
    ui->NewSongButton->setGeometry(30 * widthPercent,
                                   1790 * heightPercent,
                                   ui->NewSongButton->maximumWidth() * widthPercent,
                                   ui->NewSongButton->maximumHeight() * heightPercent);
    ui->DeleteSongButton->setGeometry(140 * widthPercent,
                                      1790 * heightPercent,
                                      ui->DeleteSongButton->maximumWidth() * widthPercent,
                                      ui->DeleteSongButton->maximumHeight() * heightPercent);
    ui->AddSongButton->setGeometry(320 * widthPercent,
                                   1790 * heightPercent,
                                   ui->AddSongButton->maximumWidth() * widthPercent,
                                   ui->AddSongButton->maximumHeight() * heightPercent);
    ui->RemoveSongButton->setGeometry(430 * widthPercent,
                                      1790 * heightPercent,
                                      ui->RemoveSongButton->maximumWidth() * widthPercent,
                                      ui->RemoveSongButton->maximumHeight() * heightPercent);
    ui->LyricsLineEdit->setGeometry(560 * widthPercent,
                                    20 * heightPercent,
                                    ui->LyricsLineEdit->maximumWidth() * widthPercent,
                                    ui->LyricsLineEdit->maximumHeight() * heightPercent);
    ui->LyricList->setGeometry(560 * widthPercent,
                               70 * heightPercent,
                               ui->LyricList->maximumWidth() * widthPercent,
                               ui->LyricList->maximumHeight() * heightPercent);
    ui->LyricTypeComboBox->setGeometry(560 * widthPercent,
                                       1480 * heightPercent,
                                       ui->LyricTypeComboBox->maximumWidth() * widthPercent,
                                       ui->LyricTypeComboBox->maximumHeight() * heightPercent);
    ui->OtherLyricTypeEdit->setGeometry(770 * widthPercent,
                                        1480 * heightPercent,
                                        ui->OtherLyricTypeEdit->maximumWidth() * widthPercent,
                                        ui->OtherLyricTypeEdit->maximumHeight() * heightPercent);
    ui->LyricTypeNumberSpinBox->setGeometry(980 * widthPercent,
                                            1480 * heightPercent,
                                            ui->LyricTypeNumberSpinBox->maximumWidth() * widthPercent,
                                            ui->LyricTypeNumberSpinBox->maximumHeight() * heightPercent);
    ui->MoveLyricUpButton->setGeometry(1220 * widthPercent,
                                       1480 * heightPercent,
                                       ui->MoveLyricUpButton->maximumWidth() * widthPercent,
                                       ui->MoveLyricUpButton->maximumHeight() * heightPercent);
    ui->MoveLyricDownButton->setGeometry(1270 * widthPercent,
                                         1480 * heightPercent,
                                         ui->MoveLyricDownButton->maximumWidth() * widthPercent,
                                         ui->MoveLyricDownButton->maximumHeight() * heightPercent);
    ui->LyricEdit->setGeometry(560 * widthPercent,
                               1530 * heightPercent,
                               ui->LyricEdit->maximumWidth() * widthPercent,
                               ui->LyricEdit->maximumHeight() * heightPercent);
    ui->AddLyricButton->setGeometry(560 * widthPercent,
                                    1790 * heightPercent,
                                    ui->AddLyricButton->maximumWidth() * widthPercent,
                                    ui->AddLyricButton->maximumHeight() * heightPercent);
    ui->DeleteLyricButton->setGeometry(670 * widthPercent,
                                       1790 * heightPercent,
                                       ui->DeleteLyricButton->maximumWidth() * widthPercent,
                                       ui->DeleteLyricButton->maximumHeight() * heightPercent);
    ui->ChangeLyricButton->setGeometry(1210 * widthPercent,
                                       1790 * heightPercent,
                                       ui->ChangeLyricButton->maximumWidth() * widthPercent,
                                       ui->ChangeLyricButton->maximumHeight() * heightPercent);
    ui->SlideText->setGeometry(1340 * widthPercent,
                               20 * heightPercent,
                               ui->SlideText->maximumWidth() * widthPercent,
                               ui->SlideText->maximumHeight() * heightPercent);
    ui->SlideBackground->setGeometry(1340 * widthPercent,
                                     20 * heightPercent,
                                     ui->SlideBackground->maximumWidth() * widthPercent,
                                     ui->SlideBackground->maximumHeight() * heightPercent);
    ui->FontLabel->setGeometry(1340 * widthPercent,
                               1120 * heightPercent,
                               ui->FontLabel->maximumWidth() * widthPercent,
                               ui->FontLabel->maximumHeight() * heightPercent);
    ui->FontComboBox->setGeometry(1550 * widthPercent,
                                  1120 * heightPercent,
                                  ui->FontComboBox->maximumWidth() * widthPercent,
                                  ui->FontComboBox->maximumHeight() * heightPercent);
    ui->FontSizeLabel->setGeometry(1770 * widthPercent,
                                   1120 * heightPercent,
                                   ui->FontSizeLabel->maximumWidth() * widthPercent,
                                   ui->FontSizeLabel->maximumHeight() * heightPercent);
    ui->FontSizeLine->setGeometry(1980 * widthPercent,
                                  1120 * heightPercent,
                                  ui->FontSizeLine->maximumWidth() * widthPercent,
                                  ui->FontSizeLine->maximumHeight() * heightPercent);
    ui->MultiplierLabel->setGeometry(2190 * widthPercent,
                                     1120 * heightPercent,
                                     ui->MultiplierLabel->maximumWidth() * widthPercent,
                                     ui->MultiplierLabel->maximumHeight() * heightPercent);
    ui->MultiplierLine->setGeometry(2240 * widthPercent,
                                    1120 * heightPercent,
                                    ui->MultiplierLine->maximumWidth() * widthPercent,
                                    ui->MultiplierLine->maximumHeight() * heightPercent);
    ui->ImageList->setGeometry(1340 * widthPercent,
                               1170 * heightPercent,
                               ui->ImageList->maximumWidth() * widthPercent,
                               ui->ImageList->maximumHeight() * heightPercent);
    ui->ErrorLabel->setGeometry(1340 * widthPercent,
                                1790 * heightPercent,
                                ui->ErrorLabel->maximumWidth() * widthPercent,
                                ui->ErrorLabel->maximumHeight() * heightPercent);
}

/**
 *  Search musics that have matching title
 */
void MainWindow::on_SearchBar_textEdited(const QString &songTitle)
{
    // Sorts mSongTitles in alphabetical order
    sort(mSongTitles.begin(), mSongTitles.end());

    // Removes all existing items in SongList
    ui->SongList->clear();

    // Override SongList widget with song with matching search title result
    for (auto title : mSongTitles)
    {
        if (title.contains(songTitle, Qt::CaseInsensitive))
        {
            ui->SongList->addItem(title);
        }
    }
}

/**
 * Remove initial text "Search title of music"
 */
void MainWindow::RemoveInitialText()
{
    if (ui->SearchBar->text() == "Search title of music")
    {
        ui->SearchBar->setText("");
    }
}

/**
 *  Adds a new song to the list
 */
void MainWindow::on_NewSongButton_clicked()
{
    // Check whether there is New Song was added previously
    QString newTitle = "New Song";
    QSqlQuery query(mSystem->GetDatabase());

    if (query.exec("SELECT MusicTitle FROM " + mSystem->GetUsername() + " ORDER BY MusicTitle ASC"))
    {
        int count = 0;
        while (query.next())
        {
            QString title = query.value(0).toString();
            if (count == 0 && title == "New Song")
            {
                ++count;
            }
            else if (count > 0 && title == "New Song (" + QString::number(count) + ")")
            {
                ++count;
            }
        }
        if (count != 0)
        {
            newTitle += " (" + QString::number(count) + ")";
        }
    }
    else
    {
        ui->ErrorLabel->setText(query.lastError().text());
    }

    // Adds a new item (New Song) in SongList widget
    ui->SongList->addItem(newTitle);

    // Adds a new song title (New Song) in mSongTitles
    mSongTitles.push_back(newTitle);

    // Adds a new song in the database
    query.prepare("INSERT INTO " + mSystem->GetUsername() + "(MusicTitle, MusicXML)" +
               "VALUES (:MusicTitle, :MusicXML)");
    query.bindValue(":MusicTitle", newTitle);
    query.bindValue(":MusicXML", "");
    if (!query.exec())
    {
        ui->ErrorLabel->setText(query.lastError().text());
    }
}

/**
 *  Delete a selected song from the list
 */
void MainWindow::on_DeleteSongButton_clicked()
{
    // Checks whether item in SongList is selected or not
    if (ui->SongList->currentItem() != nullptr)
    {
        QString deleteSongTitle = ui->SongList->currentItem()->text();      // The title of song that is selected to be deleted

        // Deletes from SelectedSongList widget
        for (auto row = 0; row < ui->SelectedSongList->count(); ++row)
        {
            if (ui->SelectedSongList->item(row)->text() == deleteSongTitle)
            {
                ui->SelectedSongList->takeItem(row);
                break;
            }
        }

        // Deletes from mSelectedSongs
        for (size_t itr = 0; itr < mSelectedSongs.size(); ++itr)
        {
            if (mSelectedSongs[itr]->GetName() == deleteSongTitle)
            {
                mSelectedSongs.erase(mSelectedSongs.begin() + itr);
                break;
            }
        }

        // Deletes from mSongTitles
        for (size_t itr = 0; itr < mSongTitles.size(); ++itr)
        {
            if (mSongTitles[itr] == deleteSongTitle)
            {
                mSongTitles.erase(mSongTitles.begin() + itr);
                break;
            }
        }

        // Delete from the database
        QSqlQuery query(mSystem->GetDatabase());
        if (!query.exec("DELETE FROM " + mSystem->GetUsername() + " WHERE MusicTitle = \'" + deleteSongTitle + "\'"))
        {
            ui->ErrorLabel->setText(query.lastError().text());
        }

        // Deletes from SongList
        ui->SongList->takeItem(ui->SongList->currentRow());

        // Delete a xml file from "songs" folder
        QFile song(mDirectory + "/songs/" + ui->SongList->currentItem()->text() + ".xml");
        song.remove();

        // Clear Lyrics
        ui->LyricList->clear();
    }
    else
    {
        qDebug() << "An item from SongList widget is not selected when DeleteButton widget was clicked";
    }
}


/**
 *  Adds a selected music to SelectedSongList widget
 */
void MainWindow::on_AddSongButton_clicked()
{
    // Checks whether an item from SongList widget is selected
    if (ui->SongList->currentItem() != nullptr)
    {
        QString addSongTitle = ui->SongList->currentItem()->text();         // The title of song that will be listed in SelectedSongList widget

        // Check whether SelectedSongList already contains selected song
        bool exist = false;
        for (auto row = 0; row < ui->SelectedSongList->count(); ++row)
        {
            if (ui->SelectedSongList->item(row)->text() == addSongTitle)
            {
                exist = true;
                break;
            }
        }

        if (!exist)
        {
            // Adds the song to SelectedSongList
            ui->SelectedSongList->addItem(addSongTitle);

            // Initialize added song
            CSong* song = new CSong(addSongTitle);
            mSelectedSongs.push_back(song);
            song->SetDirectory(mDirectory);
        }
    }
    else
    {
        qDebug() << "An item from SongList widget is not selected when AddButton widget was clicked";
    }
}


/**
 *  Removes a selected song from SelectedSongList
 */
void MainWindow::on_RemoveSongButton_clicked()
{
    // Checks whether an item from SelectedSongList widget is selected or not
    if (ui->SelectedSongList->currentItem() != nullptr)
    {
        QString removeSongTitle = ui->SelectedSongList->currentItem()->text();

        // Remove it from mSelectedSongs
        for (size_t itr = 0; itr < mSelectedSongs.size(); ++itr)
        {
            if (mSelectedSongs[itr]->GetName() == removeSongTitle)
            {
                mSelectedSongs.erase(mSelectedSongs.begin() + itr);
                break;
            }
        }

        // Removes the selected song from SelectedSongList widget
        ui->SelectedSongList->takeItem(ui->SelectedSongList->currentRow());

        // Clears Lyric
        ui->LyricList->clear();
    }
    else
    {
        qDebug() << "An item from SelectedSongList widget is not selected when RemoveButton widget was clicked";
    }
}


/**
 *  Matches the text in NameBar widget to be same as the selected item from SongList widget
 */
void MainWindow::on_SongList_itemClicked(QListWidgetItem *song)
{
    ui->NameBar->setText(song->text());
}

/**
 *  Changes the title of selected song
 */
void MainWindow::on_ChangeSongButton_clicked()
{
    // Checks whether an item fron SongList widget is selected
    if (ui->SongList->currentItem() != nullptr)
    {
        // Check whether there is New Song was added previously
        QString newTitle = ui->NameBar->text();
        QSqlQuery query(mSystem->GetDatabase());

        if (query.exec("SELECT MusicTitle FROM " + mSystem->GetUsername() + " ORDER BY MusicTitle ASC"))
        {
            int count = 0;
            while (query.next())
            {
                QString title = query.value(0).toString();
                if (count == 0 && title == newTitle)
                {
                    ++count;
                }
                else if (count > 0 && title == newTitle + " (" + QString::number(count) + ")")
                {
                    ++count;
                }
            }
            if (count != 0)
            {
                newTitle += " (" + QString::number(count) + ")";
            }
        }
        else
        {
            ui->ErrorLabel->setText(query.lastError().text());
        }

        QString previousTitle = ui->SongList->currentItem()->text();        // the previous title of song that will be used to search for what songs need to be changed
        // Adds a new title with copied xml to the database
        if (!query.exec("UPDATE " + mSystem->GetUsername() + " SET MusicTitle = \'" + newTitle + "\' WHERE MusicTitle = \'" + previousTitle + "\'"))
        {
            ui->ErrorLabel->setText(query.lastError().text());
        }

        // Changes SelectedSongList
        for (int row = 0; row < ui->SelectedSongList->count(); ++row)
        {
            if (ui->SelectedSongList->item(row)->text() == previousTitle)
            {
                ui->SelectedSongList->item(row)->setText(newTitle);
                break;
            }
        }

        // Changes mSongTitles
        for (size_t cnt = 0; cnt < mSongTitles.size(); ++cnt)
        {
            if (mSongTitles[cnt] == previousTitle)
            {
                mSongTitles[cnt] = newTitle;
                break;
            }
        }

        // Changes the name of Song
        for (size_t itr = 0; itr < mSelectedSongs.size(); ++itr)
        {
            if (mSelectedSongs[itr]->GetName() == previousTitle)
            {
                mSelectedSongs[itr]->SetName(newTitle);
                break;
            }
        }

        // Changes SongList
        ui->SongList->currentItem()->setText(newTitle);

        // Renames the file
        QFile song(mDirectory + "/songs/" + ui->SongList->currentItem()->text() + ".xml");
        if (song.open(QFile::WriteOnly | QFile::Text))
        {
            song.rename(mDirectory + "/songs/" + newTitle + ".xml");
            song.close();
        }
    }
    else
    {
        qDebug() << "An item from SongList widget is not selected when ChangeSongButton is clicked";
    }
}

/**
 *  Show lyrics in LyricList widget when an item is selected from SelectedSongList widget
 */
void MainWindow::on_SelectedSongList_itemClicked(QListWidgetItem *song)
{
    // Clears previous lyrics in LyricList
    ui->LyricList->clear();

    QString songTitle = song->text();

    // Finds where selected song is in mSelectedSongs and Initialize lyrics for selected song
    size_t num = 0;
    for (; num < mSelectedSongs.size(); ++num)
    {
        if (mSelectedSongs[num]->GetName() == songTitle)
        {
            mSelectedSongs[num]->InitializeLyrics();
            break;
        }
    }

    // Adds lyrics of selected song to LyricList
    vector<QString> lyrics = mSelectedSongs[num]->GetLyrics();
    for (size_t cnt = 0; cnt < lyrics.size(); ++cnt)
    {
        ui->LyricList->addItem(lyrics[cnt]);
    }
}

/**
 *  When an item from LyricList is selected, set up edititing widgets
 */
void MainWindow::on_LyricList_itemClicked(QListWidgetItem *lyric)
{
    QString lyricText = lyric->text();          // A text of lyric
    int index = lyricText.indexOf("\n") + 1;    // An index of QString where actual lyrics begins

    // Copies the text to LyricEdit widget
    ui->LyricEdit->setText(lyric->text().mid(index));

    // Set up LyricTypeComboBox widget to matching type of lyric
    if (lyricText.mid(0, 5) == "VERSE")
    {
        ui->LyricTypeComboBox->setCurrentIndex(0);
    }
    else if (lyricText.mid(0, 10) == "PRE-CHORUS")
    {
        ui->LyricTypeComboBox->setCurrentIndex(1);
    }
    else if (lyricText.mid(0, 6) == "CHORUS")
    {
        ui->LyricTypeComboBox->setCurrentIndex(2);
    }
    else if (lyricText.mid(0, 6) == "BRIDGE")
    {
        ui->LyricTypeComboBox->setCurrentIndex(3);
    }
    else    // Others
    {
        ui->LyricTypeComboBox->setCurrentIndex(4);
        ui->OtherLyricTypeEdit->setText(lyricText.mid(0, index - 1));
    }

    // Set up LyricTypeNumberSpinBox widget to matching number of lyric type
    for (int num = 0; num < 100; ++num)
    {
        if (lyricText.mid(index - 2, 1) == QString::number(num))
        {
            ui->LyricTypeNumberSpinBox->setValue(num);
            break;
        }
        else if (num == 99)
        {
            ui->LyricTypeNumberSpinBox->setValue(0);
        }
    }

    // Set up matching text of SlideLyric widget
    UpdateSlideLyric();
}

/**
 *  Adds Lyric to the selected song from selected song list
 */
void MainWindow::on_AddLyricButton_clicked()
{
    // Checks whether an item from SelectedSongList widget is selected
    if (ui->SelectedSongList->currentItem() != nullptr)
    {
        // Appends a new lyric to selected song from SelectedSongList widget
        QString lyricType = ui->LyricTypeComboBox->currentText();               // LyricType
        if (lyricType == "Others")
        {
            lyricType = ui->OtherLyricTypeEdit->text();
        }
        QString number = "";                                                    // LyricType number

        if (ui->LyricTypeNumberSpinBox->value() != 0)
        {
            number += QString::number(ui->LyricTypeNumberSpinBox->value());
        }

        ui->LyricList->addItem(lyricType.toUpper() + " " + number + "\n" + ui->LyricEdit->toPlainText());

        // Updates lyrics of current song
        UpdateLyrics();
    }
    else
    {
        qDebug() << "An item from SelectedSongList widget is not selected when AddLyricButton widget is clicked";
    }
}

/**
 *  Deletes a selected lyric from lyric list
 */
void MainWindow::on_DeleteLyricButton_clicked()
{
    QListWidgetItem* currentSong = ui->SelectedSongList->currentItem();
    QListWidgetItem* currentLyric = ui->LyricList->currentItem();

    // Checks whether items from both SelectedSongList widget and LyricList are selected
    if (currentSong != nullptr && currentLyric != nullptr)
    {
        ui->LyricList->takeItem(ui->LyricList->currentRow());
        UpdateLyrics();
    }
    else if (currentSong != nullptr && currentLyric == nullptr)
    {
        qDebug() << "An item from LyricList widget is not selected when DeleteLyricButton widget is clicked";
    }
    else if (currentSong == nullptr && currentLyric != nullptr)
    {
        qDebug() << "An item from SelectedSongList widget is not selected when DeleteLyricButton widget is clicked";
    }
    else
    {
        qDebug() << "Both items from SelectedSongList widget and LyricList widget are not selected when DeleteLyricButton widget is clicked";
    }
}

/**
 *  Changes a selected lyric from lyric list
 */
void MainWindow::on_ChangeLyricButton_clicked()
{
    QListWidgetItem* currentSong = ui->SelectedSongList->currentItem();
    QListWidgetItem* currentLyric = ui->LyricList->currentItem();

    // Checks whether items from both SelectedSongList widget and LyricList are selected
    if (currentSong != nullptr && currentLyric != nullptr)
    {
        // Changes the text (lyric) of selected item from LyricList widget
        QString lyricType = ui->LyricTypeComboBox->currentText();               // LyricType
        if (lyricType == "Others")
        {
            lyricType = ui->OtherLyricTypeEdit->text();
        }
        QString number = "";                                                    // LyricType Number

        if (ui->LyricTypeNumberSpinBox->value() != 0)
        {
            number += QString::number(ui->LyricTypeNumberSpinBox->value());
        }

        ui->LyricList->currentItem()->setText(lyricType.toUpper() + " " + number + "\n" + ui->LyricEdit->toPlainText());

        // Updates lyrics of current song
        UpdateLyrics();

        // Set up matching text of SlideLyric widget
        UpdateSlideLyric();
    }
    else if (currentSong != nullptr && currentLyric == nullptr)
    {
        qDebug() << "An item from LyricList widget is not selected when ChangeLyricButton widget is clicked";
    }
    else if (currentSong == nullptr && currentLyric != nullptr)
    {
        qDebug() << "An item from SelectedSongList widget is not selected when ChangeLyricButton widget is clicked";
    }
    else
    {
        qDebug() << "Both items from SelectedSongList widget and LyricList widget are not selected when ChangeLyricButton widget is clicked";
    }
}

/**
 *  Sets OtherLyricTypeEdit widget read only when Other has not been selected
 */
void MainWindow::on_LyricTypeComboBox_currentIndexChanged(int index)
{
    if (index == 4)
    {
        ui->OtherLyricTypeEdit->setReadOnly(false);
        ui->OtherLyricTypeEdit->setStyleSheet("QLineEdit {background: #FFFFFF;}");
    }
    else
    {
        ui->OtherLyricTypeEdit->setReadOnly(true);
        ui->OtherLyricTypeEdit->setStyleSheet("QLineEdit {background: #AAAAAA;}");
    }
    ui->OtherLyricTypeEdit->clear();
}

/**
 * Move currelty selected lyric up
 */
void MainWindow::on_MoveLyricUpButton_clicked()
{
    if (ui->LyricList->currentItem() != nullptr && ui->LyricList->currentRow() != 0)
    {
        int row = ui->LyricList->currentRow();

        QString currentLyric = ui->LyricList->currentItem()->text();
        QString prevLyric = ui->LyricList->item(row - 1)->text();

        ui->LyricList->currentItem()->setText(prevLyric);
        ui->LyricList->item(row - 1)->setText(currentLyric);

        ui->LyricList->setCurrentRow(row - 1);

        UpdateLyrics();
    }
}

/**
 * Move currently selected lyric down
 */
void MainWindow::on_MoveLyricDownButton_clicked()
{
    if (ui->LyricList->currentItem() != nullptr && ui->LyricList->currentRow() != ui->LyricList->count() - 1)
    {
        int row = ui->LyricList->currentRow();

        QString currentLyric = ui->LyricList->currentItem()->text();
        QString nextLyric = ui->LyricList->item(row + 1)->text();

        ui->LyricList->currentItem()->setText(nextLyric);
        ui->LyricList->item(row + 1)->setText(currentLyric);

        ui->LyricList->setCurrentRow(row + 1);

        UpdateLyrics();
    }
}



/**
 *  Sets background image of the slide
 */
void MainWindow::on_ImageList_itemClicked(QListWidgetItem *backgroundImage)
{
    QPixmap pic(mDirectory + "/background_images/" + backgroundImage->text());
    ui->SlideBackground->setPixmap(pic.scaled(ui->SlideBackground->width(),
                                              ui->SlideBackground->height(),
                                              Qt::IgnoreAspectRatio));

    // Clears previous text (lyric) that has been copied to SlideText widget
    ui->SlideText->setText("");
}

/**
 *  Changes the font style
 */
void MainWindow::on_FontComboBox_currentFontChanged(const QFont &fontStyle)
{
    QFont font = ui->SlideText->font();
    font.setStyle(fontStyle.style());
    ui->SlideText->setFont(font);
}

/**
 *  Changes the font size
 */
void MainWindow::on_FontSizeLine_textChanged(const QString &fontSize)
{
    QFont font = ui->SlideText->font();
    font.setPointSize(fontSize.toInt());
    ui->SlideText->setFont(font);
}

/**
 *  Projects a slide upon clicking ProjectButton
 */
void MainWindow::on_ProjectButton_clicked()
{
    // Checks whether an item in ImageList widget is selected
    if (ui->ImageList->currentItem() != nullptr)
    {
        mSlideWindow->SetSlide();
    }
    else
    {
        qDebug() << "An item from ImageList widget is not selected when ProjectButton widget is clicked";
    }
}

/**
 *  Bold lyrics if they are not bold; unbold lyrics if they are bold
 */
void MainWindow::on_BoldButton_clicked()
{
    mIsBold = !mIsBold;
    QFont font = ui->SlideText->font();
    font.setBold(mIsBold);
    ui->SlideText->setFont(font);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton respondButton = QMessageBox::question( this, "Main Window",
                                                                    tr("Are you sure?\n"),
                                                                    QMessageBox::No | QMessageBox::Yes,
                                                                    QMessageBox::Yes);
    if (respondButton != QMessageBox::Yes)
    {
        event->ignore();
    }
    else
    {
        QSqlQuery query(mSystem->GetDatabase());
        if (query.exec("SELECT MusicTitle FROM sleepyhong"))
        {
            while(query.next())
            {
                QFile file(mDirectory + "/songs/" + query.value(0).toString() + ".xml");
                file.remove();
            }
        }
        else
        {
            ui->ErrorLabel->setText(query.lastError().text());
        }
        event->accept();
    }
}
