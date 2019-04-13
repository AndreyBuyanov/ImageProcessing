#include "filterMedian.hpp"
#include "ui_filterMedian.h"

using ImageLib::Filters::CreateMedian3Filter;

filterMedian::filterMedian(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterMedian),
    m_Median3(CreateMedian3Filter())
{
    ui->setupUi(this);
}

filterMedian::~filterMedian()
{
    delete ui;
}
