#ifndef FILTERCANNY_HPP
#define FILTERCANNY_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/ICanny.hpp"

using std::unique_ptr;

using ImageLib::Filters::ICanny;

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
    ~filterCanny();

    // IFilterUI
    QWidget* GetUI() { return this; }
    IFilter* GetFilter() { return m_Canny.get(); }
    void ApplyParams();
private:
    Ui::filterCanny *ui;
    unique_ptr<ICanny> m_Canny;
};

#endif // FILTERCANNY_HPP
