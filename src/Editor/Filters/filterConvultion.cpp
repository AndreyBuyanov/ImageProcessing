#include "filterConvultion.hpp"
#include "ui_filterConvultion.h"

filterConvultion::filterConvultion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterConvultion)
{
    ui->setupUi(this);
}

filterConvultion::~filterConvultion()
{
    delete ui;
}
