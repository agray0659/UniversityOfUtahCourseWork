#include "main_window.h"
#include "sprite_editor_model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sprite_Editor_Model model;
    Main_Window w(model);
    w.show();
    return a.exec();
}
