#include "filterRoberts.hpp"
#include "ui_filterRoberts.h"

filterRoberts::filterRoberts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterRoberts),
    m_Roberts(ImageLib::Filters::CreateRobertsFilter())
{
    ui->setupUi(this);
}

filterRoberts::~filterRoberts()
{
    delete ui;
}
