#include "pixel_editor.h"
#include <QMouseEvent>
#include <QPainter>
#include <vector>

// Constructs a pixel editing object
PixelEditor::PixelEditor(QWidget *parent)
    : QWidget{parent}, pixelColors(20, 20)
{
    // Default color is white
    selectedColor = Qt::white;

    this->setMouseTracking(true);
    isGridSetUp = false;
}

// Updates the color and grid data of the pixel editor based on the passed frame
void PixelEditor::setFrameData(Frame newFrame) {

    // Calculates the size of cells in the grid for display
    int width = newFrame.width;
    int height = newFrame.height;
    rectHorizontalSize = this->width() / width;
    rectVerticalSize = this->height() / height;

    pixelColors = newFrame;
    if (!pixelGrid.empty()) {
        pixelGrid.clear();
    }

    for (int i = 0; i < height; i++) {
        pixelGrid.push_back(std::vector<QRect>());
        for (int j = 0; j < width; j++) {
            pixelGrid[i].push_back(QRect(j * rectHorizontalSize,
                                         i * rectVerticalSize,
                                         rectHorizontalSize,
                                         rectVerticalSize));
        }
    }

    isGridSetUp = true;
}

// When the mouse is pressed, fill in the selected cell in the grid
void PixelEditor::mousePressEvent(QMouseEvent *ev) {
    if (isGridSetUp && ev->buttons() == Qt::LeftButton && isOverGrid(ev->position().x(), ev->position().y())) {
        unsigned int clickedRectCol = ev->position().x() / rectHorizontalSize;
        unsigned int clickedRectRow = ev->position().y() / rectVerticalSize;

        if (clickedRectRow < pixelColors.currentImage.size() && clickedRectCol < pixelColors.currentImage[0].size()) {
            Pixel p(selectedColor);
            pixelColors.currentImage[clickedRectRow][clickedRectCol] = p;
            emit pixelModified(clickedRectRow, clickedRectCol, selectedColor);
        }
        update();
    }
}

// When the mouse is dragged while being clicked and is over the grid, fill in the cells passed over
// Also, set the cell that is being hovered over
void PixelEditor::mouseMoveEvent(QMouseEvent *ev) {
    if (isGridSetUp && ev->buttons() == Qt::LeftButton && isOverGrid(ev->position().x(), ev->position().y())) {
        unsigned int clickedRectCol = ev->position().x() / rectHorizontalSize;
        unsigned int clickedRectRow = ev->position().y() / rectVerticalSize;

        if (clickedRectRow < pixelColors.currentImage.size() && clickedRectCol < pixelColors.currentImage[0].size()) {
            Pixel p(selectedColor);
            pixelColors.currentImage[clickedRectRow][clickedRectCol] = p;
            emit pixelModified(clickedRectRow, clickedRectCol, selectedColor);
            isHovering = false;
        }
        update();
    }

    else if (isGridSetUp && isOverGrid(ev->position().x(), ev->position().y())) {
        unsigned int hoveredRectCol = ev->position().x() / rectHorizontalSize;
        unsigned int hoveredRectRow = ev->position().y() / rectVerticalSize;

        if (hoveredRectRow < pixelColors.currentImage.size() && hoveredRectCol < pixelColors.currentImage[0].size()) {
            isHovering = true;
            hoveredRow = hoveredRectRow;
            hoveredCol = hoveredRectCol;
        }
        update();
    }
}

// When a new color is selected by the user, update the selected color
void PixelEditor::colorChanged(QColor newColor) {
    selectedColor = newColor;
}

// Redraw the cells of the grid using the information in the frame
void PixelEditor::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPen pen(Qt::black);
    pen.setWidth(1);
    painter.setPen(pen);

    if (isGridSetUp) {
        for (unsigned int i = 0; i < pixelGrid.size(); i++) {
            for (unsigned int j = 0; j < pixelGrid[i].size(); j++) {
                // Highlight a cell if one is being hovered over
                if (isHovering && i == hoveredRow && j == hoveredCol) {
                    if (pixelColors.currentImage[i][j].color == Qt::transparent)
                        painter.fillRect(pixelGrid[i][j], QBrush(Qt::white));
                    else
                        painter.fillRect(pixelGrid[i][j], QBrush(pixelColors.currentImage[i][j].color.lighter()));

                    // Draw a rectangle around the highlighted cell for clarity
                    painter.drawRect(QRect(pixelGrid[i][j].x(),
                                           pixelGrid[i][j].y(),
                                           pixelGrid[i][j].width()-1,
                                           pixelGrid[i][j].height()-1));
                }
                else
                    painter.fillRect(pixelGrid[i][j], QBrush(pixelColors.currentImage[i][j].color));
            }
        }

        // Draw outline around widget
        painter.drawRect(QRect(0, 0, this->width()-1, this->height()-1));
    }
}

// Determines if the cursor is within this widget's bounds
bool PixelEditor::isOverGrid(int mouseX, int mouseY) {
    if (mouseX < 0 || mouseX > this->width() || mouseY < 0 || mouseY > this->height())
        return false;
    return true;
}
