#include "sprite.h"
#include "frame.h"

//sprite contructor
Sprite::Sprite(int width_, int height_)
{
    width = width_;
    height = height_;
}

//creates an empty frame at the end of allFrames
void Sprite::addEmptyFrame() {
    Frame newFrame(width, height);
    newFrame.fillTransparent();
    AllFrames.push_back(newFrame);
}

//adds a frame to the end of allFrames from frameData
void Sprite::addFrame(std::vector<std::vector<std::vector<int>>> frameData) {
    Frame newFrame(width, height);

    for (unsigned int i = 0; i < frameData.size(); i++) {
        newFrame.setPixelRow(i, frameData[i]);
    }

    AllFrames.push_back(newFrame);
}

//sets the size of the frames within the sprite
void Sprite::setSize(int width_, int height_) {
    width = width_;
    height = height_;
}

//gets the frame from allFrames at index frameNumber
Frame Sprite::getFrame(int frameNumber) {
    return AllFrames[frameNumber];
}

//sets a pixel within a frame of AllFrames to a color
void Sprite::setPixel(int row, int col, QColor color, int activeFrameIdx) {
    AllFrames[activeFrameIdx].updatePixel(row, col, color);
}

//gets the width of the frames
int Sprite::getWidth() {
    return width;
}

//gets the height of the frames
int Sprite::getHeight() {
    return height;
}

//gets the total number of frames
int Sprite::getNumFrames() {
    return AllFrames.size();
}

//clears the backing array of frames, resets size to static values
void Sprite::clearData() {
    AllFrames.clear();
    width = 20;
    height = 20;
}
