#include "sprite_editor_model.h"

// Constructs a model object
Sprite_Editor_Model::Sprite_Editor_Model()
{
    activeFrameIdx = 0;
    hasNextFrame = false;
    hasPrevFrame = false;
}

// Sets up a sprite within the editor from a given JSON file
void Sprite_Editor_Model::loadSpriteFromFile(QString filename) {
    if (!JsonParser::loadSpriteFromFile(sprite, filename))
        return;

    activeFrameIdx = 0;
    hasNextFrame = false;
    hasPrevFrame = false;
    if (sprite.getNumFrames() > 1) {
        hasNextFrame = true;
    }
    emit hasNextAndPrevFrames(hasNextFrame, hasPrevFrame);
    emit spriteLoaded(sprite.getFrame(activeFrameIdx));
}

// Sets up a new blank sprite
void Sprite_Editor_Model::newSprite(int width, int height) {
    sprite.clearData();
    sprite.setSize(width, height);
    sprite.addEmptyFrame();
    activeFrameIdx = 0;
    hasNextFrame = false;
    hasPrevFrame = false;
    emit hasNextAndPrevFrames(hasNextFrame, hasPrevFrame);
    emit spriteLoaded(sprite.getFrame(activeFrameIdx));
}

// Updates a given pixel within a sprite
void Sprite_Editor_Model::updateSpritePixel(int row, int col, QColor color) {
    sprite.setPixel(row, col, color, activeFrameIdx);
}

// Writes a sprite's data in JSON format to a file
void Sprite_Editor_Model::saveSprite(QString filename) {
    JsonParser::saveSpriteToFile(sprite, filename);
}

// Sends the preview data to the view
void Sprite_Editor_Model::generatePreview() {
    emit spritePreviewData(activeFrameIdx, sprite);
}

// Sends the next frame's data to the view
void Sprite_Editor_Model::nextFrame() {
    if (hasNextFrame) {
        activeFrameIdx++;

        if (activeFrameIdx == sprite.getNumFrames() - 1)
            hasNextFrame = false;

        hasPrevFrame = true;
        emit hasNextAndPrevFrames(hasNextFrame, hasPrevFrame);
        emit sendNextFrame(sprite.getFrame(activeFrameIdx));
    }
}

// Sends the previous frame's data to the view
void Sprite_Editor_Model::prevFrame() {
    if (hasPrevFrame) {
        activeFrameIdx--;

        if (activeFrameIdx == 0)
            hasPrevFrame = false;

        hasNextFrame = true;
        emit hasNextAndPrevFrames(hasNextFrame, hasPrevFrame);
        emit sendPrevFrame(sprite.getFrame(activeFrameIdx));
    }
}

// Adds a new frame to the working sprite
void Sprite_Editor_Model::newFrame() {
    sprite.addEmptyFrame();

    activeFrameIdx = sprite.getNumFrames() - 1;
    hasPrevFrame = true;
    hasNextFrame = false;
    emit hasNextAndPrevFrames(hasNextFrame, hasPrevFrame);
    emit sendNewFrame(sprite.getFrame(activeFrameIdx));
}
