#ifndef SLIDEWINDOW_H
#define SLIDEWINDOW_H

#include "HardWorshipSystem.h"

#include <QMainWindow>
#include <QListWidgetItem>
#include <QLabel>
#include <QKeyEvent>
#include <QFontComboBox>
#include <QLineEdit>
#include <QFont>
#include <QGraphicsDropShadowEffect>

#include <memory>

namespace Ui { class SlideWindow; }

class MainWindow;

class SlideWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SlideWindow(QWidget *parent = nullptr);
    ~SlideWindow();

    Ui::SlideWindow* GetUi() {return ui;}
    void SetUi(Ui::SlideWindow* newUi) {ui = newUi;}

    MainWindow* GetMainWindow() {return mMainWindow;}
    void SetMainWindow(MainWindow* mainWindow) {mMainWindow = mainWindow;}

    std::shared_ptr<CHardWorshipSystem> GetSystem() {return mSystem;}
    void SetSystem(std::shared_ptr<CHardWorshipSystem> system)
    {
        mSystem = system;
        system->SetSlideWindow(this);
    }

private:
    void keyPressEvent(QKeyEvent *event);
    void resizeEvent(QResizeEvent* event);

public slots:
    void SetSlide();

private slots:
    void on_FullScreenButton_clicked();

private:
    Ui::SlideWindow *ui;

    MainWindow* mMainWindow;                    // MainWindow it belongs to

    QPixmap mBackgroundImage;
    QGraphicsDropShadowEffect *mShadowEffect;

    std::shared_ptr<CHardWorshipSystem> mSystem;
};

#endif // SLIDEWINDOW_H
