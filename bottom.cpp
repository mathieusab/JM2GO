#include "bottom.h"
#include "ui_bottom.h"

Bottom::Bottom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bottom)
{
    ui->setupUi(this);
}

Bottom::~Bottom()
{
    delete ui;
}
