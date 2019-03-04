#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QImage>
#include <QProgressBar>
#include <QTime>
#include <QLabel>

#include <memory>

#include "ImageLib/ImageLib.hpp"
#include "ImageLib/Events.hpp"

using std::unique_ptr;

using ImageLib::IBitmap;
using ImageLib::Filters::IInvert;
using ImageLib::Filters::IGrayscale;
using ImageLib::Filters::IConvultion3x3;
using ImageLib::Filters::IGamma;
using ImageLib::Filters::IMedian3;
using ImageLib::IFilterControlEventHandler;
using ImageLib::IProgressEventHandler;

namespace Ui {
class MainWindow;
}

class MainWindow :
        public QMainWindow,
        public IFilterControlEventHandler,
		public IProgressEventHandler
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // IFilterControlEventHandler
    void FilterStarted();
    void FilterFinished();

	// IProgressEventHandler
	void UpdateProgress(
		const int32_t percent);

private slots:
    void on_actionOpen_triggered();

    void on_actionInvert_triggered();

    void on_actionGrayscale_triggered();

    void on_actionConvultion_triggered();

    void on_actionGamma_correction_triggered();

    void on_actionMedian_3_triggered();

private:
    Ui::MainWindow *ui;
	QProgressBar *m_FilterProgress;
	QTime t;
	QLabel *m_FilterTimeLabel;

    QImage m_Image;
    unique_ptr<IBitmap> m_Bitmap;
    unique_ptr<IInvert> m_Invert;
    unique_ptr<IGrayscale> m_Grayscale;
    unique_ptr<IConvultion3x3> m_Convultion3x3;
    unique_ptr<IGamma> m_Gamma;
    unique_ptr<IMedian3> m_Median3;
};

#endif // MAINWINDOW_HPP
