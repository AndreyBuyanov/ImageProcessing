#include "filterGrayscale.hpp"
#include "ui_filterGrayscale.h"

filterGrayscale::filterGrayscale(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterGrayscale)
{
    ui->setupUi(this);
}

filterGrayscale::~filterGrayscale()
{
    delete ui;
}
