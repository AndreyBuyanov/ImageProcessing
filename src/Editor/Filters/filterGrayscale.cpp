#include "filterGrayscale.hpp"
#include "ui_filterGrayscale.h"

filterGrayscale::filterGrayscale(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterGrayscale),
    m_Grayscale(ImageLib::Filters::CreateGrayscaleFilter())
{
    ui->setupUi(this);
}

filterGrayscale::~filterGrayscale()
{
    delete ui;
}
