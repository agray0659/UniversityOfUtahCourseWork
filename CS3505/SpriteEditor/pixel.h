#ifndef PIXEL_H
#define PIXEL_H
#include <QColor>

/*
Group: Brigham Young's basketball Club

Group members: Griffin Zody, Ryan Sloan, Kevin Xue, Alex Gray

Course: CS 3505 - 001

Assignment: A7 Sprite Editor

Description: Contains the RGBA data for a pixel.

*/
class Pixel
{

public:
    Pixel(QColor color_);

    // Stores RGBA values
    QColor color;
};

#endif // PIXEL_H
