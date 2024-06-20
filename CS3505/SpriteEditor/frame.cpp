#include "frame.h"

// Constructs a frame object based on given height and width
Frame::Frame(int width_, int height_)
{
    height = height_;
    width = width_;

    for (int i = 0; i < height; i++) {
        currentImage.push_back(std::vector<Pixel>());

        for (int j = 0; j < width; j++) {
            currentImage[i].push_back(Pixel(Qt::transparent));
        }
    }

}

// Sets a pixel within the frame to the specified color
void Frame::updatePixel(int row, int col, QColor color) {
    currentImage[row][col] = color;
}

// Fills the frame with transparent pixels
void Frame::fillTransparent() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            currentImage[i][j] = Pixel(Qt::transparent);
        }
    }
}

// Sets a row within the frame to the passed pixels
void Frame::setPixelRow(int row, std::vector<std::vector<int>> pixelRow) {
    for (unsigned int i = 0; i < pixelRow.size(); i++) {
        QColor pixelColor = QColor(pixelRow[i][0],
                pixelRow[i][1],
                pixelRow[i][2],
                pixelRow[i][3]);

        currentImage[row][i] = Pixel(pixelColor);
    }
}
