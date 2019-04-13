#include "filterInvert.hpp"
#include "ui_filterInvert.h"

using ImageLib::Filters::CreateInvertFilter;

filterInvert::filterInvert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterInvert),
    m_Invert(CreateInvertFilter())
{
    ui->setupUi(this);
}

filterInvert::~filterInvert()
{
    delete ui;
}
