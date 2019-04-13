#include "filterConvultion.hpp"
#include "ui_filterConvultion.h"

using ImageLib::Filters::CreateConvultion3x3Filter;

using ImageLib::Filters::Kernel3x3;

filterConvultion::filterConvultion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterConvultion),
    m_Convultion3x3(CreateConvultion3x3Filter())
{
    ui->setupUi(this);
}

filterConvultion::~filterConvultion()
{
    delete ui;
}

void filterConvultion::ApplyParams()
{
    Kernel3x3 kernel = {
        ui->le11->text().toFloat(),
        ui->le12->text().toFloat(),
        ui->le13->text().toFloat(),
        ui->le21->text().toFloat(),
        ui->le22->text().toFloat(),
        ui->le23->text().toFloat(), 
        ui->le31->text().toFloat(),
        ui->le32->text().toFloat(),
        ui->le33->text().toFloat() };

    m_Convultion3x3->SetKernel(kernel);
}
