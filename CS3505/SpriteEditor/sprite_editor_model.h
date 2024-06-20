#ifndef SPRITE_EDITOR_MODEL_H
#define SPRITE_EDITOR_MODEL_H

#include "sprite.h"
#include <QObject>
#include "json_parser.h"
#include <QPixmap>

/*
Group: Brigham Young's basketball Club

Group members: Griffin Zody, Ryan Sloan, Kevin Xue, Alex Gray

Course: CS 3505 - 001

Assignment: A7 Sprite Editor

Description: Represents a sprite editor. Contains information about the working sprite as well as the active frame.
Communicates stored data to the view and controller.

*/
class Sprite_Editor_Model : public QObject
{
    Q_OBJECT
public:
    Sprite_Editor_Model();

signals:
    void spriteLoaded(Frame activeFrame);
    void spritePreviewData(int activeFrame, Sprite sprite);
    void sendNextFrame(Frame nextFrame);
    void sendPrevFrame(Frame prevFrame);
    void sendNewFrame(Frame newFrame);
    void hasNextAndPrevFrames(bool hasNextFrame, bool hasPrevFrame);

public slots:
    void loadSpriteFromFile(QString filename);
    void newSprite(int width, int height);
    void generatePreview();
    void saveSprite(QString filename);
    void updateSpritePixel(int row, int col, QColor color);
    void nextFrame();
    void prevFrame();
    void newFrame();

private:
    // Contains frame and color information
    Sprite sprite;

    // Handles saving and loading sprites
    JsonParser jsonParser;

    // Tracks the frame that the user is on
    int activeFrameIdx;

    // Tracks whether the sprite has a next frame based on the active frame
    bool hasNextFrame;

    // Tracks whether the sprite has a previous frame based on the active frame
    bool hasPrevFrame;
};

#endif // SPRITE_EDITOR_MODEL_H
