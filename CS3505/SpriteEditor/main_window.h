#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QDir>
#include "sprite_editor_model.h"
#include "preview.h"
#include "spritepreview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Main_Window; }
QT_END_NAMESPACE

/*
Group: Brigham Young's basketball Club

Group members: Griffin Zody, Ryan Sloan, Kevin Xue, Alex Gray

Course: CS 3505 - 001

Assignment: A7 Sprite Editor

Description: main window representation for our sprite editor application

*/

class Main_Window : public QMainWindow
{
    Q_OBJECT

public:
    Main_Window(Sprite_Editor_Model &model_, QWidget *parent = nullptr);
    ~Main_Window();

signals:
    void newSprite(int width, int height);
    void newColorSelected(QColor selectedColor);
    void loadSpriteFromFile(QString filename);
    void saveSprite(QString filename);
    void generatePreview();

private slots:
    void on_actionNew_triggered();
    void on_colorPickerButton_clicked();
    void on_actionLoad_triggered();
    void on_eraseButton_clicked();
    void on_actionSave_triggered();
    void on_previewSprite_clicked();
    void displayPreviewWindow(int activeFrameIdx, Sprite spriteToPreview);
    void toggleNextAndPrevButtons(bool hasNextFrame, bool hasPrevFrame);

private:
    Ui::Main_Window *ui;
    QAction *actionNew;
    SpritePreview previewUi;

};
#endif // MAIN_WINDOW_H
