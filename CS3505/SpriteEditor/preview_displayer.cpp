#include "preview_displayer.h"
#include <QMouseEvent>
#include <QPainter>
#include <vector>

// Constructs a preview displayer object
PreviewDisplayer::PreviewDisplayer(QWidget *parent)
    : QWidget{parent}, pixelColors{0,0}
{
    isGridSetUp = false;
}

// Updates the color and grid data of the pixel editor based on the passed frame
void PreviewDisplayer::setFrameData(Frame newFrame) {

    // Calculates the size of cells in the grid for display
    int width = newFrame.width;
    int height = newFrame.height;
    rectHorizontalSize = this->width() / width;
    rectVerticalSize = this->height() / height;

    pixelColors = newFrame;
    if (!pixelGrid.empty()) {
        pixelGrid.clear();
    }

    for (int i = 0; i < height; i++) {
        pixelGrid.push_back(std::vector<QRect>());
        for (int j = 0; j < width; j++) {
            pixelGrid[i].push_back(QRect(j * rectHorizontalSize,
                                         i * rectVerticalSize,
                                         rectHorizontalSize,
                                         rectVerticalSize));
        }
    }

    isGridSetUp = true;
    update();
}

// When the mouse is pressed, fill in the selected cell in the grid
void PreviewDisplayer::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    if (isGridSetUp) {
        for (unsigned int i = 0; i < pixelGrid.size(); i++) {
            for (unsigned int j = 0; j < pixelGrid[i].size(); j++) {
                painter.fillRect(pixelGrid[i][j], QBrush(pixelColors.currentImage[i][j].color));
            }
        }

        painter.drawRect(QRect(0, 0, this->width()-1, this->height()-1));
    }
}

// Helper method for animating frames
void PreviewDisplayer::setCurrFrame(Sprite sprite, int &currFrameIdx) {
    setFrameData(sprite.getFrame(currFrameIdx));
    currFrameIdx++;
}

