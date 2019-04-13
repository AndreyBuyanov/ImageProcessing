#ifndef FILTERINVERT_HPP
#define FILTERINVERT_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/IInvert.hpp"

using std::unique_ptr;

using ImageLib::Filters::IInvert;

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
    ~filterInvert();

    // IFilterUI
    QWidget* GetUI() { return this; }
    IFilter* GetFilter() { return m_Invert.get(); }
    void ApplyParams() {}
private:
    Ui::filterInvert *ui;
    unique_ptr<IInvert> m_Invert;
};

#endif // FILTERINVERT_HPP
