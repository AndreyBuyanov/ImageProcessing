#ifndef FILTERCONVOLUTION_HPP
#define FILTERCONVOLUTION_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/IConvolution.hpp"

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
    ~filterConvolution() override;

    // IFilterUI
    QWidget* GetUI() override { return this; }
    ImageLib::Filters::IFilter* GetFilter() override { return m_Convolution3x3.get(); }
    void ApplyParams() override;

private slots:
    void loadPreset(int index);
private:
    Ui::filterConvolution *ui;
    std::unique_ptr<ImageLib::Filters::IConvolution3x3> m_Convolution3x3;
};

#endif // FILTERCONVOLUTION_HPP
