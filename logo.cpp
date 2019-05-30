#include "logo.h"
#include "ui_logo.h"
#include <QDebug>

Logo::Logo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Logo)
{
    ui->setupUi(this);
//    QPalette p;
//    p = palette();
//    p.setBrush(QPalette::Window, QBrush(QPixmap("tram.jpg")));
//    setPalette(p);
    ui->frame->setStyleSheet("background-image:url(\"tram.jpg\"); background-position: center; border-image: url(\"tram.jpg\") 0 0 0 0 stretch stretch;");
    //pLabel->setStyleSheet("QLabel { background-color : red; color : blue; }");

}

Logo::~Logo()
{
    delete ui;
}
