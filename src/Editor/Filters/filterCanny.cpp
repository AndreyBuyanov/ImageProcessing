#include "filterCanny.hpp"
#include "ui_filterCanny.h"

filterCanny::filterCanny(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterCanny),
    m_Canny(ImageLib::Filters::CreateCannyFilter())
{
    ui->setupUi(this);
}

filterCanny::~filterCanny()
{
    delete ui;
}

void filterCanny::ApplyParams()
{
    m_Canny->SetSigma(ui->leSigma->text().toFloat());
    m_Canny->SetLowThreshold(ui->leLowThreshold->text().toFloat());
    m_Canny->SetHighThreshold(ui->leHighThreshold->text().toFloat());
}
