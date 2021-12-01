#include "filterConvultion.hpp"
#include "ui_filterConvultion.h"

#include <vector>

using std::vector;
using std::pair;
using std::make_pair;

using ImageLib::Filters::CreateConvultion3x3Filter;

using ImageLib::Filters::Kernel3x3;

const vector<pair<QString, Kernel3x3>> presets = 
{
    make_pair("Blur", Kernel3x3(
        0.0625f, 0.1250f, 0.0625f,
        0.1250f, 0.2500f, 0.1250f,
        0.0625f, 0.1250f, 0.0625f)),
    make_pair("Laplasian", Kernel3x3(
         0.0f, -1.0f,  0.0f,
        -1.0f,  4.0f, -1.0f,
         0.0f, -1.0f,  0.0f)),
    make_pair("Laplasian (diagonals)", Kernel3x3(
        -1.0f, -1.0f, -1.0f,
        -1.0f,  8.0f, -1.0f,
        -1.0f, -1.0f, -1.0f)),
    make_pair("Embross", Kernel3x3(
        -2.0f, -1.0f,  0.0f,
        -1.0f,  1.0f,  1.0f,
         0.0f,  1.0f,  2.0f)),
    make_pair("Outline", Kernel3x3(
        -1.0f, -1.0f, -1.0f,
        -1.0f,  8.0f, -1.0f,
        -1.0f, -1.0f, -1.0f))
};

filterConvultion::filterConvultion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterConvultion),
    m_Convultion3x3(CreateConvultion3x3Filter())
{
    ui->setupUi(this);
    connect(ui->cbPreset, SIGNAL(currentIndexChanged(int)), this, SLOT(loadPreset(int)));
    for (auto &p : presets) {
        ui->cbPreset->addItem(p.first);
    }
}

filterConvultion::~filterConvultion()
{
    delete ui;
}

void filterConvultion::loadPreset(int index)
{
    Kernel3x3 k = presets[index].second;
    ui->le11->setText(QString::number(k.k1));
    ui->le12->setText(QString::number(k.k2));
    ui->le13->setText(QString::number(k.k3));
    ui->le21->setText(QString::number(k.k4));
    ui->le22->setText(QString::number(k.k5));
    ui->le23->setText(QString::number(k.k6));
    ui->le31->setText(QString::number(k.k7));
    ui->le32->setText(QString::number(k.k8));
    ui->le33->setText(QString::number(k.k9));
    m_Convultion3x3->SetKernel(k);
}

void filterConvultion::ApplyParams()
{
    Kernel3x3 kernel = {
        ui->le11->text().toFloat(),
        ui->le12->text().toFloat(),
        ui->le13->text().toFloat(),
        ui->le21->text().toFloat(),
        ui->le22->text().toFloat(),
        ui->le23->text().toFloat(), 
        ui->le31->text().toFloat(),
        ui->le32->text().toFloat(),
        ui->le33->text().toFloat() };

    m_Convultion3x3->SetKernel(kernel);
}
