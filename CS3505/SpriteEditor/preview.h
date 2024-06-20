#ifndef PREVIEW_H
#define PREVIEW_H

#include <QWidget>

namespace Ui {
class preview;
}

class preview : public QWidget
{
    Q_OBJECT

public:
    explicit preview(QWidget *parent = nullptr);
    ~preview();

private slots:
    void on_actualSize_toggled(bool checked);

    void on_fps_valueChanged(int arg1);

private:
    Ui::preview *ui;
};

#endif // PREVIEW_H
