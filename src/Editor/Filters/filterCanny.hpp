#ifndef FILTERCANNY_HPP
#define FILTERCANNY_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/ICanny.hpp"

namespace Ui {
class filterCanny;
}

class filterCanny :
    public QWidget,
    public IFilterUI
{
    Q_OBJECT

public:
    explicit filterCanny(QWidget *parent = nullptr);
    ~filterCanny() override;

    // IFilterUI
    QWidget* GetUI() override { return this; }
    ImageLib::Filters::IFilter* GetFilter() override { return m_Canny.get(); }
    void ApplyParams() override;
private:
    Ui::filterCanny *ui;
    std::unique_ptr<ImageLib::Filters::ICanny> m_Canny;
};

#endif // FILTERCANNY_HPP
