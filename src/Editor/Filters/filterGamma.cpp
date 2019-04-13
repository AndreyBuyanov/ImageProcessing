#include "filterGamma.hpp"
#include "ui_filterGamma.h"

filterGamma::filterGamma(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterGamma)
{
    ui->setupUi(this);
}

filterGamma::~filterGamma()
{
    delete ui;
}
