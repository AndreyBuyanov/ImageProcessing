#include "filterMedian.hpp"
#include "ui_filterMedian.h"

filterMedian::filterMedian(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterMedian)
{
    ui->setupUi(this);
}

filterMedian::~filterMedian()
{
    delete ui;
}
