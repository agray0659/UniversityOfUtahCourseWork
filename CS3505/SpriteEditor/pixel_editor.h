#ifndef PIXEL_EDITOR_H
#define PIXEL_EDITOR_H

#include <QWidget>
#include <vector>
#include "frame.h"

/*
Group: Brigham Young's basketball Club

Group members: Griffin Zody, Ryan Sloan, Kevin Xue, Alex Gray

Course: CS 3505 - 001

Assignment: A7 Sprite Editor

Description: A custom widget that allows the user to modify drawn pixels. Model for editing pixels
within a frame.

*/
class PixelEditor : public QWidget
{
    Q_OBJECT
public:
    explicit PixelEditor(QWidget *parent = nullptr);

public slots:
    void setFrameData(Frame newFrame);
    void colorChanged(QColor newColor);

signals:
    void pixelModified(int row, int col, QColor color);

private:
    bool isOverGrid(int mouseX, int mouseY);

    // Stores the location of pixels in the image
    std::vector<std::vector<QRect>> pixelGrid;

    // Stores the colors of pixels in the image
    Frame pixelColors;

    // The horizontal size of each cell in the grid
    int rectHorizontalSize;

    // The vertical size of each cell in the grid
    int rectVerticalSize;

    // The color selected for drawing with
    QColor selectedColor;

    // Determines if the widget is ready for drawing
    bool isGridSetUp;

    // Stores the row of a pixel the user is hovering over
    unsigned int hoveredRow;

    // Stores the column of a pixel the user is hovering over
    unsigned int hoveredCol;

    // Determines if the user is hovering over a pixel in the grid
    bool isHovering;

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *);

};

#endif // PIXEL_EDITOR_H
