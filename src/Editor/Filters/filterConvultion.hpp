#ifndef FILTERCONVULTION_HPP
#define FILTERCONVULTION_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/IConvultion.hpp"

using std::unique_ptr;

using ImageLib::Filters::IConvultion3x3;

namespace Ui {
class filterConvultion;
}

class filterConvultion :
	public QWidget,
	public IFilterUI
{
    Q_OBJECT

public:
    explicit filterConvultion(QWidget *parent = nullptr);
    ~filterConvultion();

	// IFilterUI
	QWidget* GetUI() { return this; }
	IFilter* GetFilter() { return m_Convultion3x3.get(); }
	void ApplyParams();

private slots:
    void loadPreset(int index);
private:
    Ui::filterConvultion *ui;
	unique_ptr<IConvultion3x3> m_Convultion3x3;
};

#endif // FILTERCONVULTION_HPP
