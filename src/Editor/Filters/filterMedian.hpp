#ifndef FILTERMEDIAN_HPP
#define FILTERMEDIAN_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/IMedian.hpp"

using std::unique_ptr;

using ImageLib::Filters::IMedian3;

namespace Ui {
class filterMedian;
}

class filterMedian :
    public QWidget,
    public IFilterUI
{
    Q_OBJECT

public:
    explicit filterMedian(QWidget *parent = nullptr);
    ~filterMedian();

    // IFilterUI
    QWidget* GetUI() { return this; }
    IFilter* GetFilter() { return m_Median3.get(); }
    void ApplyParams() {}
private:
    Ui::filterMedian *ui;
    unique_ptr<IMedian3> m_Median3;
};

#endif // FILTERMEDIAN_HPP
