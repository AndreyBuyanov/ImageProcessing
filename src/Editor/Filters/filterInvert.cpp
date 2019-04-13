#include "filterInvert.hpp"
#include "ui_filterInvert.h"

filterInvert::filterInvert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterInvert)
{
    ui->setupUi(this);
}

filterInvert::~filterInvert()
{
    delete ui;
}
