#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <QFileDialog>

#include "ImageLib/IBitmap.hpp"
#include "ImageLib/Filters/IInvert.hpp"
#include "ImageLib/Filters/IGrayscale.hpp"
#include "ImageLib/Filters/IConvultion.hpp"
#include "ImageLib/Filters/IGamma.hpp"
#include "ImageLib/Filters/IMedian.hpp"

using ImageLib::CreateBitmap;
using ImageLib::BitmapInfo;
using ImageLib::BitmapFormat;

using ImageLib::Filters::CreateInvertFilter;
using ImageLib::Filters::CreateGrayscaleFilter;
using ImageLib::Filters::CreateConvultion3x3Filter;
using ImageLib::Filters::CreateGammaFilter;
using ImageLib::Filters::CreateMedian3Filter;

using ImageLib::Filters::Kernel3x3;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
	m_FilterProgress(new QProgressBar(this)),
	m_FilterTimeLabel(new QLabel(this))
{
    ui->setupUi(this);
	m_FilterProgress->setRange(0, 100);

	ui->statusBar->addWidget(m_FilterProgress);
	ui->statusBar->addWidget(m_FilterTimeLabel);

    m_Invert.reset(CreateInvertFilter());

    m_Invert->RegisterFilterControlEventHandler(this);
	m_Invert->RegisterProgressEventHandler(this);

    m_Grayscale.reset(CreateGrayscaleFilter());

    m_Grayscale->RegisterFilterControlEventHandler(this);
    m_Grayscale->RegisterProgressEventHandler(this);

    m_Convultion3x3.reset(CreateConvultion3x3Filter());

    m_Convultion3x3->RegisterFilterControlEventHandler(this);
    m_Convultion3x3->RegisterProgressEventHandler(this);

    m_Gamma.reset(CreateGammaFilter());

    m_Gamma->RegisterFilterControlEventHandler(this);
    m_Gamma->RegisterProgressEventHandler(this);

    m_Median3.reset(CreateMedian3Filter());

    m_Median3->RegisterFilterControlEventHandler(this);
    m_Median3->RegisterProgressEventHandler(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FilterStarted()
{
	t.start();
	QMetaObject::invokeMethod(m_FilterProgress, "setValue", Qt::QueuedConnection, Q_ARG(int, 0));
}

void MainWindow::FilterFinished()
{
	QMetaObject::invokeMethod(m_FilterProgress, "setValue", Qt::QueuedConnection, Q_ARG(int, 100));
	QMetaObject::invokeMethod(ui->canvas, "repaint", Qt::QueuedConnection);
	QString strTime = QString("Time: %1 ms").arg(t.elapsed());
	QMetaObject::invokeMethod(m_FilterTimeLabel, "setText", Qt::QueuedConnection, Q_ARG(QString, strTime));
}

void MainWindow::UpdateProgress(
	const int32_t percent)
{
	QMetaObject::invokeMethod(m_FilterProgress, "setValue", Qt::QueuedConnection, Q_ARG(int, percent));
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open Image"),
        "",
        tr("Image Files (*.png *.jpg *.bmp)"));

    if(fileName != ""){
        QImage tmpImage(fileName);
        m_Image = tmpImage.convertToFormat(QImage::Format_ARGB32);
        ui->canvas->setImage(&m_Image);
        BitmapInfo info = {
            m_Image.bits(),
            static_cast<uint32_t>(m_Image.width()),
            static_cast<uint32_t>(m_Image.height()),
            BitmapFormat::RGBA};
		m_Bitmap.reset(CreateBitmap(info));
        ui->canvas->repaint();
    }
}

void MainWindow::on_actionInvert_triggered()
{
    m_Invert->SetBitmap(m_Bitmap.get());
	m_Invert->ProcessBitmap();
}

void MainWindow::on_actionGrayscale_triggered()
{
    m_Grayscale->SetBitmap(m_Bitmap.get());
    m_Grayscale->ProcessBitmap();
}

void MainWindow::on_actionConvultion_triggered()
{
    m_Convultion3x3->SetBitmap(m_Bitmap.get());
    Kernel3x3 kernel = {
         0.0f, -1.0f,  0.0f,
        -1.0f,  4.0f, -1.0f,
         0.0f, -1.0f,  0.0f};
    m_Convultion3x3->SetKernel(kernel);
    m_Convultion3x3->ProcessBitmap();
}

void MainWindow::on_actionGamma_correction_triggered()
{
    m_Gamma->SetBitmap(m_Bitmap.get());
    m_Gamma->SetGamma(2.5f);
    m_Gamma->ProcessBitmap();
}

void MainWindow::on_actionMedian_3_triggered()
{
    m_Median3->SetBitmap(m_Bitmap.get());
    m_Median3->ProcessBitmap();
}
