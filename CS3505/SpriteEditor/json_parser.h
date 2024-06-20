#ifndef JSONPARSER_H
#define JSONPARSER_H
#include "sprite.h"
#include <QJsonDocument>

/*
Group: Brigham Young's basketball Club

Group members: Griffin Zody, Ryan Sloan, Kevin Xue, Alex Gray

Course: CS 3505 - 001

Assignment: A7 Sprite Editor

Description: Parsing code used to save and load sprites to files using Json Data structure.

*/
class JsonParser
{
public:
    static bool loadSpriteFromFile(Sprite &spriteToLoadInto, QString filepath);
    static void saveSpriteToFile(Sprite sprite, QString filepath);
};

#endif // JSONPARSER_H
