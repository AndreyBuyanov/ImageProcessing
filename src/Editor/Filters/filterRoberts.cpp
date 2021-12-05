#include "filterRoberts.hpp"
#include "ui_filterRoberts.h"

using ImageLib::Filters::CreateRobertsFilter;

filterRoberts::filterRoberts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterRoberts),
    m_Roberts(CreateRobertsFilter())
{
    ui->setupUi(this);
}

filterRoberts::~filterRoberts()
{
    delete ui;
}
