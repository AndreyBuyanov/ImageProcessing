#include "filterSobel.hpp"
#include "ui_filterSobel.h"

using ImageLib::Filters::CreateSobelFilter;

filterSobel::filterSobel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterSobel),
    m_Sobel(CreateSobelFilter())
{
    ui->setupUi(this);
}

filterSobel::~filterSobel()
{
    delete ui;
}
