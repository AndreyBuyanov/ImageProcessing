#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <QFileDialog>
#include <QVariant>

#include "ImageLib/IBitmap.hpp"

#include "Filters/filterConvolution.hpp"
#include "Filters/filterGamma.hpp"
#include "Filters/filterGrayscale.hpp"
#include "Filters/filterInvert.hpp"
#include "Filters/filterMedian.hpp"
#include "Filters/filterSobel.hpp"
#include "Filters/filterRoberts.hpp"
#include "Filters/filterCanny.hpp"

Q_DECLARE_METATYPE(IFilterUI*)

void MainWindow::AddFilter(IFilterUI* f)
{
    f->GetUI()->setVisible(false);
    ui->frFilter->layout()->addWidget(f->GetUI());
    f->GetFilter()->RegisterFilterControlEventHandler(this);
    f->GetFilter()->RegisterProgressEventHandler(this);
    QVariant v;
    v.setValue(f);
    ui->cbFilters->addItem(QString(f->GetFilter()->GetName().c_str()), v);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
	m_FilterProgress(new QProgressBar(this)),
	m_FilterTimeLabel(new QLabel(this)),
    m_CurrentFilter(nullptr)
{
    ui->setupUi(this);
	m_FilterProgress->setRange(0, 100);

	ui->statusBar->addWidget(m_FilterProgress);
	ui->statusBar->addWidget(m_FilterTimeLabel);

    connect(ui->cbFilters, SIGNAL(currentIndexChanged(int)), this, SLOT(selectFilter(int)));

    IFilterUI* f = nullptr;

    f = new filterConvolution(ui->frFilter);
    AddFilter(f);

    f = new filterGamma(ui->frFilter);
    AddFilter(f);

    f = new filterGrayscale(ui->frFilter);
    AddFilter(f);

    f = new filterInvert(ui->frFilter);
    AddFilter(f);

    f = new filterMedian(ui->frFilter);
    AddFilter(f);

    f = new filterSobel(ui->frFilter);
    AddFilter(f);

    f = new filterRoberts(ui->frFilter);
    AddFilter(f);

    f = new filterCanny(ui->frFilter);
    AddFilter(f);
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
        ImageLib::BitmapInfo info = {
            m_Image.bits(),
            static_cast<uint32_t>(m_Image.width()),
            static_cast<uint32_t>(m_Image.height()),
            ImageLib::BitmapFormat::RGBA };
		m_Bitmap.reset(CreateBitmap(info));
        ui->canvas->repaint();
    }
}

void MainWindow::on_actionSave_As_triggered()
{

}

void MainWindow::on_actionExit_triggered()
{

}

void MainWindow::selectFilter(int index)
{
    if (m_CurrentFilter) {
        m_CurrentFilter->GetUI()->setVisible(false);
    }
    m_CurrentFilter = (ui->cbFilters->currentData()).value<IFilterUI*>();
    if (m_CurrentFilter) {
        m_CurrentFilter->GetUI()->setVisible(true);
    }
}

void MainWindow::on_pbApplyFilter_clicked()
{
    m_CurrentFilter->ApplyParams();
    m_CurrentFilter->GetFilter()->SetBitmap(m_Bitmap.get());
    m_CurrentFilter->GetFilter()->ProcessBitmap();
}
