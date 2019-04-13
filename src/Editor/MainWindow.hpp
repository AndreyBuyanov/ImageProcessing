#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QImage>
#include <QProgressBar>
#include <QTime>
#include <QLabel>

#include <memory>
#include <vector>

#include "ImageLib/Events.hpp"

#include "IFilterUI.hpp"

using std::unique_ptr;
using std::vector;

using ImageLib::IBitmap;
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

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void selectFilter(int index);

    void on_pbApplyFilter_clicked();

private:
    Ui::MainWindow *ui;
	QProgressBar *m_FilterProgress;
	QTime t;
	QLabel *m_FilterTimeLabel;

    QImage m_Image;
    unique_ptr<IBitmap> m_Bitmap;
    IFilterUI* m_CurrentFilter;

    void AddFilter(IFilterUI* f);
};

#endif // MAINWINDOW_HPP
