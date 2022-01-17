#ifndef FILTERMEDIAN_HPP
#define FILTERMEDIAN_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/IMedian.hpp"

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
    ~filterMedian() override;

    // IFilterUI
    QWidget* GetUI() override { return this; }
    ImageLib::Filters::IFilter* GetFilter() override { return m_Median3.get(); }
    void ApplyParams() override {}
private:
    Ui::filterMedian *ui;
    std::unique_ptr<ImageLib::Filters::IMedian3> m_Median3;
};

#endif // FILTERMEDIAN_HPP
