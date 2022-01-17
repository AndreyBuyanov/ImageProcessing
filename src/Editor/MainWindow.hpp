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

namespace Ui {
class MainWindow;
}

class MainWindow :
    public QMainWindow,
    public ImageLib::IFilterControlEventHandler,
    public ImageLib::IProgressEventHandler
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    // IFilterControlEventHandler
    void FilterStarted() override;
    void FilterFinished() override;

	// IProgressEventHandler
	void UpdateProgress(
		int32_t percent) override;

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
    std::unique_ptr<ImageLib::IBitmap> m_Bitmap;
    IFilterUI* m_CurrentFilter;

    void AddFilter(IFilterUI* f);
};

#endif // MAINWINDOW_HPP
