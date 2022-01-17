#include "filterSobel.hpp"
#include "ui_filterSobel.h"

filterSobel::filterSobel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterSobel),
    m_Sobel(ImageLib::Filters::CreateSobelFilter())
{
    ui->setupUi(this);
}

filterSobel::~filterSobel()
{
    delete ui;
}
