#ifndef FILTERSOBEL_HPP
#define FILTERSOBEL_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/ISobel.hpp"

using std::unique_ptr;

using ImageLib::Filters::ISobel;

namespace Ui {
class filterSobel;
}

class filterSobel :
    public QWidget,
    public IFilterUI
{
    Q_OBJECT

public:
    explicit filterSobel(QWidget *parent = nullptr);
    ~filterSobel();

    // IFilterUI
    QWidget* GetUI() { return this; }
    IFilter* GetFilter() { return m_Sobel.get(); }
    void ApplyParams() {}
private:
    Ui::filterSobel *ui;
    unique_ptr<ISobel> m_Sobel;
};

#endif // FILTERSOBEL_HPP
