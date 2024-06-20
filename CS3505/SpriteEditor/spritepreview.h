#ifndef SPRITEPREVIEW_H
#define SPRITEPREVIEW_H

#include <QDialog>
#include <QPixmap>
#include "sprite.h"
#include <QTimer>

/*
Group: Brigham Young's basketball Club

Group members: Griffin Zody, Ryan Sloan, Kevin Xue, Alex Gray

Course: CS 3505 - 001

Assignment: A7 Sprite Editor

Description: Ui window functionality for secondary window used to view full Sprite animation with fps control

*/

namespace Ui {
class SpritePreview;
}

class SpritePreview : public QDialog
{
    Q_OBJECT

public:
    explicit SpritePreview(QWidget *parent = nullptr);
    ~SpritePreview();
    void setSpriteToDisplay(int activeFrameIdx, Sprite spriteToPreview);
    void setIsActualSize(bool isActualSize_);

public slots:
    void updatePreviewDisplay();

private slots:
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::SpritePreview *ui;

    //keeps track of whether to resize the preview frame
    bool isActualSize;

    //starting width of an unsized frame
    const int STARTING_WIDTH = 411;

    //starting height of an unsized frame
    const int STARTING_HEIGHT = 411;

    //sprite that needs to be previewed
    Sprite spriteToPreview;

    //integer of the current frame index
    int activeFrameIdx;

    //integer of the current animation frame index
    int currAnimationFrameIdx;

    //timer for animation purposes
    QTimer *timer;
};

#endif // SPRITEPREVIEW_H
