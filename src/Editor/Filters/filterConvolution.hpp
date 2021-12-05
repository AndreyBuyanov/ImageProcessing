#ifndef FILTERCONVOLUTION_HPP
#define FILTERCONVOLUTION_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/IConvolution.hpp"

using std::unique_ptr;

using ImageLib::Filters::IConvolution3x3;

namespace Ui {
class filterConvolution;
}

class filterConvolution :
	public QWidget,
	public IFilterUI
{
    Q_OBJECT

public:
    explicit filterConvolution(QWidget *parent = nullptr);
    ~filterConvolution();

	// IFilterUI
	QWidget* GetUI() { return this; }
	IFilter* GetFilter() { return m_Convolution3x3.get(); }
	void ApplyParams();

private slots:
    void loadPreset(int index);
private:
    Ui::filterConvolution *ui;
	unique_ptr<IConvolution3x3> m_Convolution3x3;
};

#endif // FILTERCONVOLUTION_HPP
