#ifndef FRAME_H
#define FRAME_H
#include "pixel.h"
#include <iostream>
#include <vector>
#include <QImage>
#include <QRgb>

/*
Group: Brigham Young's basketball Club

Group members: Griffin Zody, Ryan Sloan, Kevin Xue, Alex Gray

Course: CS 3505 - 001

Assignment: A7 Sprite Editor

Description: Represents a single frame object with pixel information.

*/
class Frame
{
public:
    Frame(int width_, int height_);
    void updateImage();
    void updatePixel(int row, int col, QColor color);
    void setPixelRow(int row, std::vector<std::vector<int>> pixelRow);
    void fillTransparent();

    // Stores the pixel information
    std::vector<std::vector<Pixel>> currentImage;

    // The number of pixels in a row
    int width;

    // The number of pixels in a column
    int height;
};

#endif // FRAME_H
