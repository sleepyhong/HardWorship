#include "SlideWindow.h"
#include "ui_slidewindow.h"
#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QMainWindow>
#include <QDir>

/**
 *  Constructor
 */
SlideWindow::SlideWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::SlideWindow)
{
    ui->setupUi(this);

    mSystem = nullptr;

    // Initizlie Shadow Effect
    mShadowEffect = new QGraphicsDropShadowEffect(this);
    mShadowEffect->setBlurRadius(10);
    mShadowEffect->setColor(QColor("#000000"));
    mShadowEffect->setOffset(1, 1);
    ui->LyricLabel->setGraphicsEffect(mShadowEffect);
    ui->LyricLabel->setStyleSheet("QLabel { color: #ffffff; }");

    // Default Background Image
    mBackgroundImage = QPixmap(QDir::currentPath() + "/background_images/background_default.jpg");
    mBackgroundImage = mBackgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, mBackgroundImage);
    this->setPalette(palette);
}

/**
 *  Destructor
 */
SlideWindow::~SlideWindow()
{
    delete ui;
    delete mShadowEffect;
}

/**
 *  Somthing happens when key is pressed
 *  @param event
 *      esc = exit fullscreen mode
 */
void SlideWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        this->showMaximized();

        // FullScreenButton Visible again
        ui->FullScreenButton->setFlat(false);
        ui->FullScreenButton->setText("FullScreen");
    }
}

/**
 *  Matches the size of labels to the size of window
 *  @param event
 */
void SlideWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    // Make Labels as large as the window
    mBackgroundImage = mBackgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, mBackgroundImage);
    this->setPalette(palette);

    ui->LyricLabel->resize(this->width(), this->height());
}

/**
 *  Enter FullScreen mode
 */
void SlideWindow::on_FullScreenButton_clicked()
{
    this->showFullScreen();

    // FullScreenButotn invisible
    ui->FullScreenButton->setFlat(true);
    ui->FullScreenButton->setText("");
}

/**
 *  Copies background image and text from MainWindow's SlideText and SlideBackground
 */
void SlideWindow::SetSlide()
{
    // Project background image
    mBackgroundImage = QPixmap(mMainWindow->GetDirectory() + "/background_images/" + mMainWindow->GetUi()->ImageList->currentItem()->text());
    mBackgroundImage = mBackgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, mBackgroundImage);
    this->setPalette(palette);

    // Set up Font-Style and Font-Size for a label
    QFont font = mMainWindow->GetUi()->SlideText->font();
    font.setPointSize(font.pointSize() * mMainWindow->GetUi()->MultiplierLine->text().toDouble());
    ui->LyricLabel->setFont(font);

    // Give final touch (shadow effect) to new lyrics
    ui->LyricLabel->setText(mMainWindow->GetUi()->SlideText->text());
}
