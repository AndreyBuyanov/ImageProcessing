#include "filterMedian.hpp"
#include "ui_filterMedian.h"

filterMedian::filterMedian(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterMedian),
    m_Median3(ImageLib::Filters::CreateMedian3Filter())
{
    ui->setupUi(this);
}

filterMedian::~filterMedian()
{
    delete ui;
}
