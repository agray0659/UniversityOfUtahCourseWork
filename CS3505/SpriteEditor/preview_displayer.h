#ifndef PREVIEWDISPLAYER_H
#define PREVIEWDISPLAYER_H

#include <QWidget>
#include <vector>
#include "frame.h"
#include "sprite.h"

/*
Group: Brigham Young's basketball Club

Group members: Griffin Zody, Ryan Sloan, Kevin Xue, Alex Gray

Course: CS 3505 - 001

Assignment: A7 Sprite Editor

Description: A custom widget that displays a given frame and allows a sprite's animation to be viewed.

*/
class PreviewDisplayer: public QWidget
{
    Q_OBJECT
public:
    explicit PreviewDisplayer(QWidget *parent = nullptr);

public slots:
    void setFrameData(Frame newFrame);
    void setCurrFrame(Sprite sprite, int &currFrameIdx);

private:
    // Stores the location of pixels in the image
    std::vector<std::vector<QRect>> pixelGrid;

    // Stores the colors of pixels in the image
    Frame pixelColors;

    // The horizontal size of each cell in the grid
    int rectHorizontalSize;

    // The vertical size of each cell in the grid
    int rectVerticalSize;

    // Determines if the widget is ready for drawing
    bool isGridSetUp;

protected:
    void paintEvent(QPaintEvent *);

};

#endif // PREVIEWDISPLAYER_H
