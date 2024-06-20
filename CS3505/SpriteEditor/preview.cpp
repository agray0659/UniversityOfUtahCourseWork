#include "preview.h"
#include "ui_preview.h"

preview::preview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::preview)
{
    ui->setupUi(this);
}

preview::~preview()
{
    delete ui;
}

void preview::on_actualSize_toggled(bool checked)
{

}


void preview::on_fps_valueChanged(int arg1)
{

}

