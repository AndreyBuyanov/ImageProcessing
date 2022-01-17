#include "filterGamma.hpp"
#include "ui_filterGamma.h"

filterGamma::filterGamma(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterGamma),
    m_Gamma(ImageLib::Filters::CreateGammaFilter())
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
