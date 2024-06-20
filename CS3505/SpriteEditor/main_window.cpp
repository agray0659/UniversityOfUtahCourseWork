#include "main_window.h"
#include "ui_main_window.h"
#include <QColorDialog>
#include <QFileDialog>
#include "preview_displayer.h"

//sets up the main window. disables all of the buttons while no sprite is present
Main_Window::Main_Window(Sprite_Editor_Model &model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Main_Window)
{
    ui->setupUi(this);
    ui->newFrame->setDisabled(true);
    ui->nextFrame->setDisabled(true);
    ui->previousFrame->setDisabled(true);
    ui->colorPickerButton->setDisabled(true);
    ui->eraseButton->setDisabled(true);
    ui->previewSprite->setDisabled(true);
    ui->actualSizeCheckBox->setDisabled(true);

    //connects the slots with their signals
    connect(this, &Main_Window::newSprite, &model, &Sprite_Editor_Model::newSprite);
    connect(this, &Main_Window::loadSpriteFromFile, &model, &Sprite_Editor_Model::loadSpriteFromFile);
    connect(this, &Main_Window::saveSprite, &model, &Sprite_Editor_Model::saveSprite);
    connect(this, &Main_Window::generatePreview, &model, &Sprite_Editor_Model::generatePreview);
    connect(&model, &Sprite_Editor_Model::spriteLoaded, ui->pixelEditor, &PixelEditor::setFrameData);
    connect(&model, &Sprite_Editor_Model::spritePreviewData, this, &Main_Window::displayPreviewWindow);
    connect(ui->pixelEditor, &PixelEditor::pixelModified, &model, &Sprite_Editor_Model::updateSpritePixel);
    connect(this, &Main_Window::newColorSelected, ui->pixelEditor, &PixelEditor::colorChanged);
    connect(ui->nextFrame, &QPushButton::clicked, &model, &Sprite_Editor_Model::nextFrame);
    connect(&model, &Sprite_Editor_Model::sendNextFrame, ui->pixelEditor, &PixelEditor::setFrameData);
    connect(ui->previousFrame, &QPushButton::clicked, &model, &Sprite_Editor_Model::prevFrame);
    connect(&model, &Sprite_Editor_Model::sendPrevFrame, ui->pixelEditor, &PixelEditor::setFrameData);
    connect(&model, &Sprite_Editor_Model::hasNextAndPrevFrames, this, &Main_Window::toggleNextAndPrevButtons);
    connect(ui->newFrame, &QPushButton::clicked, &model, &Sprite_Editor_Model::newFrame);
    connect(&model, &Sprite_Editor_Model::sendNewFrame, ui->pixelEditor, &PixelEditor::setFrameData);
}

//destructor for the main window
Main_Window::~Main_Window()
{
    delete ui;
}

//slot method for when the new button is clicked, activates all of the functions of the pixel editor
void Main_Window::on_actionNew_triggered()
{
    int width = QInputDialog::getInt(this, tr("Set Size"),
                                         tr("Width : "));
    int height = QInputDialog::getInt(this, tr("Set Size"),
                                         tr("Height : "));
    ui->newFrame->setDisabled(false);
    ui->nextFrame->setDisabled(false);
    ui->previousFrame->setDisabled(false);
    ui->colorPickerButton->setDisabled(false);
    ui->eraseButton->setDisabled(false);
    ui->previewSprite->setDisabled(false);
    ui->actualSizeCheckBox->setDisabled(false);
    emit newSprite(width, height);
}

//slot method for when the color selector is clicked, emits a signal that contains the selected color
void Main_Window::on_colorPickerButton_clicked()
{
    QColor selectedColor = QColorDialog::getColor(Qt::white, this);
    emit newColorSelected(selectedColor);
}

//slot method for when the load button is clicked, activates all functions
//emits a signal to load the sprite from the file
void Main_Window::on_actionLoad_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Sprite File"),
                                                    "/", tr("Sprites (*.ssp)"));

    ui->newFrame->setDisabled(false);
    ui->nextFrame->setDisabled(false);
    ui->previousFrame->setDisabled(false);
    ui->colorPickerButton->setDisabled(false);
    ui->eraseButton->setDisabled(false);
    ui->previewSprite->setDisabled(false);
    ui->actualSizeCheckBox->setDisabled(false);

    emit loadSpriteFromFile(fileName);
}

//slot method for when the erase button is clicked
//sets the color to transparents and emits signal that notifies that new color was selected
void Main_Window::on_eraseButton_clicked()
{
    QColor selectedColor = QColorConstants::Transparent;
    emit newColorSelected(selectedColor);
}

//slot method for when the save button is clicked
//emits a signal to notify to safe current file to json
void Main_Window::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,
            tr("Save Sprite"), "",
            tr("Sprites (*.ssp);;All Files (*)"));

    emit saveSprite(filename);
}

//slot method for when the preview sprite button is clicked
//notifies the generate preview signal
void Main_Window::on_previewSprite_clicked()
{
    emit generatePreview();
}

//creates the second ui and sets the second ui to the "usable" ui
void Main_Window::displayPreviewWindow(int activeFrameIdx, Sprite spriteToDisplay) {
    previewUi.setIsActualSize(ui->actualSizeCheckBox->isChecked());
    previewUi.setSpriteToDisplay(activeFrameIdx, spriteToDisplay);
    previewUi.exec();
}

//method to disable the next and previous frame buttons
void Main_Window::toggleNextAndPrevButtons(bool hasNextFrame, bool hasPrevFrame) {
    if (!hasNextFrame) {
        ui->nextFrame->setDisabled(true);
    }
    else {
        ui->nextFrame->setDisabled(false);
    }

    if (!hasPrevFrame) {
        ui->previousFrame->setDisabled(true);
    }
    else {
        ui->previousFrame->setDisabled(false);
    }
}

