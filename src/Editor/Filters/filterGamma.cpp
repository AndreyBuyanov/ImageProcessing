#include "filterGamma.hpp"
#include "ui_filterGamma.h"

using ImageLib::Filters::CreateGammaFilter;

filterGamma::filterGamma(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterGamma),
    m_Gamma(CreateGammaFilter())
{
    ui->setupUi(this);
}

filterGamma::~filterGamma()
{
    delete ui;
}

void filterGamma::ApplyParams()
{
    m_Gamma->SetGamma(ui->leGamma->text().toFloat());
}
