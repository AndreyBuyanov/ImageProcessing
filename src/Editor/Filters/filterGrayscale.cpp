#include "filterGrayscale.hpp"
#include "ui_filterGrayscale.h"

using ImageLib::Filters::CreateGrayscaleFilter;

filterGrayscale::filterGrayscale(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterGrayscale),
    m_Grayscale(CreateGrayscaleFilter())
{
    ui->setupUi(this);
}

filterGrayscale::~filterGrayscale()
{
    delete ui;
}
