#include "json_parser.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>

// Takes in a sprite file and updates it with information from a JSON file if it fits the sprite
// JSON format outline by the CS 3505 guidelines. Returns true if successful, false if not
bool JsonParser::loadSpriteFromFile(Sprite &spriteToLoadInto, QString filepath) {
    std::string strFilepath = filepath.toStdString();
    QFile file(QString::fromStdString(strFilepath));
    if (!file.open(QIODevice::ReadOnly))
        return false;

    // Read from file
    QTextStream fileText(&file);
    QString jsonString;
    jsonString = fileText.readAll();
    file.close();
    QByteArray jsonBytes = jsonString.toLocal8Bit();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonBytes);

    if (jsonDoc.isNull())
        return false;

    if (!jsonDoc.isObject())
        return false;

    QJsonObject jsonObject = jsonDoc.object();
    if (jsonObject.isEmpty())
        return false;

    // Read data from a height property
    int height = -1;
    if (!jsonObject.keys().contains("height"))
        return false;
    else {
        QJsonValue value = jsonObject.value("height");
        if (!value.isDouble())
            return false;

        height = value.toInt();
    }

    // Read data from a width property
    int width = -1;
    if (!jsonObject.keys().contains("width"))
        return false;
    else {
        QJsonValue value = jsonObject.value("width");
        if (!value.isDouble())
            return false;

        width = value.toInt();
    }

    // Read data from a numberOfFrames property
    int numFrames = -1;
    if (!jsonObject.keys().contains("numberOfFrames"))
        return false;
    else {
        QJsonValue value = jsonObject.value("numberOfFrames");
        if (!value.isDouble())
            return false;

        numFrames = value.toInt();
    }

    // Read data from a frames property
    std::vector<std::vector<std::vector<std::vector<int>>>> frames;
    if (!jsonObject.keys().contains("frames"))
        return false;
    else {
        QJsonValue value = jsonObject.value("frames");
        if (!value.isObject())
            return false;

        QJsonObject framesJson = value.toObject();
        for(int i = 0; i < framesJson.keys().size(); i++) {
            QJsonValue frameVal = framesJson.value(framesJson.keys().at(i));
            if (!frameVal.isArray())
                return false;

            frames.push_back(std::vector<std::vector<std::vector<int>>>());
            QJsonArray rowArr = frameVal.toArray();
            for (int j = 0; j < rowArr.size(); j++) {
                QJsonValue rowObj = rowArr.at(j);
                if (!rowObj.isArray())
                    return false;

                frames[i].push_back(std::vector<std::vector<int>>());
                QJsonArray pixelArr = rowObj.toArray();
                for (int k = 0; k < pixelArr.size(); k++) {
                    QJsonValue pixelObj = pixelArr.at(k);
                    if (!pixelObj.isArray())
                        return false;

                    frames[i][j].push_back(std::vector<int>());
                    QJsonArray intArr = pixelObj.toArray();
                    QJsonValue intVal;
                    for (unsigned int l = 0; l < intArr.size(); l++) {
                        intVal = intArr.at(l);
                        if (!intVal.isDouble())
                            return false;

                        frames[i][j][k].push_back(intVal.toInt());
                    }
                }
            }
        }
    }

    // If all data successfully retrieved, clear the sprite and load the data
    spriteToLoadInto.clearData();
    spriteToLoadInto.setSize(width, height);
    for (int i = 0; i < numFrames; i++) {
        spriteToLoadInto.addFrame(frames[i]);
    }

    return true;
}

// Save the sprite data to a JSON file
void JsonParser::saveSpriteToFile(Sprite sprite, QString filepath) {
    QJsonDocument jsonDoc;

    QJsonObject jsonDocObj;
    jsonDocObj.insert("height", QJsonValue::fromVariant(sprite.getHeight()));
    jsonDocObj.insert("width", QJsonValue::fromVariant(sprite.getWidth()));
    jsonDocObj.insert("numberOfFrames", QJsonValue::fromVariant(sprite.getNumFrames()));
    QJsonObject frameObj;
    for (int i = 0; i < sprite.getNumFrames(); i++) {
        Frame currFrame = sprite.getFrame(i);

        QJsonArray rowArr;
        QString frameString = QString::fromStdString("frame" + std::to_string(i));
        for (int j = 0; j < currFrame.height; j++) {
            std::vector<Pixel> pixelArr = currFrame.currentImage[j];

            QJsonArray rowPixelArr;
            for (unsigned int k = 0; k < pixelArr.size(); k++) {
                Pixel currPixel = pixelArr[k];

                QJsonArray pixelIntArr;
                pixelIntArr.push_back(currPixel.color.red());
                pixelIntArr.push_back(currPixel.color.green());
                pixelIntArr.push_back(currPixel.color.blue());
                pixelIntArr.push_back(currPixel.color.alpha());

                rowPixelArr.push_back(pixelIntArr);
            }
            rowArr.push_back(rowPixelArr);
        }
        frameObj.insert(frameString, rowArr);
    }
    jsonDocObj.insert("frames", frameObj);

    jsonDoc.setObject(jsonDocObj);

    QFile file( filepath );
    if( file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
    {
        file.write(jsonDoc.toJson(QJsonDocument::Compact));
        file.close();
    }
}
