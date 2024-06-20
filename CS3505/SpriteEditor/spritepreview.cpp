#include "spritepreview.h"
#include "ui_spritepreview.h"
#include "preview_displayer.h"

SpritePreview::SpritePreview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpritePreview)
{
    ui->setupUi(this);
    isActualSize = false;
    timer = new QTimer(this);
}

SpritePreview::~SpritePreview()
{
    delete ui;
}

//displays the current frame, resizes if the user pressed actual size
void SpritePreview::setSpriteToDisplay(int activeFrameIdx_, Sprite spriteToPreview_) {
    if (isActualSize) {
        ui->previewDisplayer->resize(spriteToPreview.getWidth(), spriteToPreview.getHeight());
    }
    else {
        ui->previewDisplayer->resize(STARTING_WIDTH, STARTING_HEIGHT);
    }

    int x = (this->width() - ui->previewDisplayer->width()) / 2;
    int y = (this->height() - ui->previewDisplayer->height()) / 2 - 50;
    ui->previewDisplayer->move(x, y);

    spriteToPreview = spriteToPreview_;
    activeFrameIdx = activeFrameIdx_;
    ui->previewDisplayer->setFrameData(spriteToPreview.getFrame(activeFrameIdx));
}

//sets the actualSize instance variable
void SpritePreview::setIsActualSize(bool isActualSize_){
    isActualSize = isActualSize_;
}

//creates an animation if the user changes the fps of the sprite animation
void SpritePreview::on_spinBox_valueChanged(int fpsVal)
{
    if (fpsVal == 0) {
        if (timer->isActive())
            timer->stop();

        // Display active frame statically
        ui->previewDisplayer->setFrameData(spriteToPreview.getFrame(activeFrameIdx));
    }
    else {
        if (timer->isActive())
            timer->stop();

        // Start a slideshow at the given fps
        currAnimationFrameIdx = activeFrameIdx;
        connect(timer, SIGNAL(timeout()),
                  this, SLOT(updatePreviewDisplay()));
        timer->setInterval(1.0/(double)fpsVal * 1000.0);
        timer->start();

    }
}

//updates the display for the animation frame
void SpritePreview::updatePreviewDisplay() {
    ui->previewDisplayer->setFrameData(spriteToPreview.getFrame(currAnimationFrameIdx));
    if (currAnimationFrameIdx + 1 == spriteToPreview.getNumFrames())
        currAnimationFrameIdx = 0;
    else
        currAnimationFrameIdx++;
}

