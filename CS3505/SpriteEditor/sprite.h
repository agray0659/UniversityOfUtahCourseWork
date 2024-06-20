#ifndef SPRITE_H
#define SPRITE_H
#include "frame.h"

/*
Group: Brigham Young's basketball Club

Group members: Griffin Zody, Ryan Sloan, Kevin Xue, Alex Gray

Course: CS 3505 - 001

Assignment: A7 Sprite Editor

Description: Sprite representation for our pixel editor application

*/
class Sprite
{
public:
    Sprite(int width_=20, int height_=20);
    void addEmptyFrame();
    void clearData();
    void addFrame(std::vector<std::vector<std::vector<int>>> frameData);
    Frame getFrame(int frameNumber);
    void setSize(int width_, int height_);
    int getWidth();
    int getHeight();
    int getNumFrames();
    void setPixel(int row, int col, QColor color, int activeFrameIdx);

private:
    //a vector containing all of the frames present in this sprite
    std::vector<Frame> AllFrames;

    //the width of the sprite
    int width;

    //the height of the sprite
    int height;
};

#endif // SPRITE_H
