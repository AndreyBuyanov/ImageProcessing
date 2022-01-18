#include "filterConvolution.hpp"
#include "ui_filterConvolution.h"

#include <vector>

const std::vector<std::pair<QString, ImageLib::Filters::Kernel3x3>> presets =
{
    std::make_pair("Blur", ImageLib::Filters::Kernel3x3(
        0.0625f, 0.1250f, 0.0625f,
        0.1250f, 0.2500f, 0.1250f,
        0.0625f, 0.1250f, 0.0625f)),
    std::make_pair("Laplasian", ImageLib::Filters::Kernel3x3(
         0.0f, -1.0f,  0.0f,
        -1.0f,  4.0f, -1.0f,
         0.0f, -1.0f,  0.0f)),
    std::make_pair("Laplasian (diagonals)", ImageLib::Filters::Kernel3x3(
        -1.0f, -1.0f, -1.0f,
        -1.0f,  8.0f, -1.0f,
        -1.0f, -1.0f, -1.0f)),
    std::make_pair("Embross", ImageLib::Filters::Kernel3x3(
        -2.0f, -1.0f,  0.0f,
        -1.0f,  1.0f,  1.0f,
         0.0f,  1.0f,  2.0f)),
    std::make_pair("Outline", ImageLib::Filters::Kernel3x3(
        -1.0f, -1.0f, -1.0f,
        -1.0f,  8.0f, -1.0f,
        -1.0f, -1.0f, -1.0f))
};

filterConvolution::filterConvolution(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterConvolution),
    m_Convolution3x3(ImageLib::Filters::CreateConvolution3x3Filter())
{
    ui->setupUi(this);
    connect(ui->cbPreset, SIGNAL(currentIndexChanged(int)), this, SLOT(loadPreset(int)));
    for (auto &p : presets) {
        ui->cbPreset->addItem(p.first);
    }
}

filterConvolution::~filterConvolution()
{
    delete ui;
}

void filterConvolution::loadPreset(int index)
{
    ImageLib::Filters::Kernel3x3 k = presets[index].second;
    ui->le11->setText(QString::number(k[0][0]));
    ui->le12->setText(QString::number(k[0][1]));
    ui->le13->setText(QString::number(k[0][2]));
    ui->le21->setText(QString::number(k[1][0]));
    ui->le22->setText(QString::number(k[1][1]));
    ui->le23->setText(QString::number(k[1][2]));
    ui->le31->setText(QString::number(k[2][0]));
    ui->le32->setText(QString::number(k[2][1]));
    ui->le33->setText(QString::number(k[2][2]));
    m_Convolution3x3->SetKernel(k);
}

void filterConvolution::ApplyParams()
{
    ImageLib::Filters::Kernel3x3 kernel = {
        ui->le11->text().toFloat(),
        ui->le12->text().toFloat(),
        ui->le13->text().toFloat(),
        ui->le21->text().toFloat(),
        ui->le22->text().toFloat(),
        ui->le23->text().toFloat(), 
        ui->le31->text().toFloat(),
        ui->le32->text().toFloat(),
        ui->le33->text().toFloat() };

    m_Convolution3x3->SetKernel(kernel);
}
