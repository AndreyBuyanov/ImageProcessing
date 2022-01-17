#ifndef FILTERINVERT_HPP
#define FILTERINVERT_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/IInvert.hpp"

namespace Ui {
class filterInvert;
}

class filterInvert :
    public QWidget,
    public IFilterUI
{
    Q_OBJECT

public:
    explicit filterInvert(QWidget *parent = nullptr);
    ~filterInvert() override;

    // IFilterUI
    QWidget* GetUI() override { return this; }
    ImageLib::Filters::IFilter* GetFilter() override { return m_Invert.get(); }
    void ApplyParams() override {}
private:
    Ui::filterInvert *ui;
    std::unique_ptr<ImageLib::Filters::IInvert> m_Invert;
};

#endif // FILTERINVERT_HPP
