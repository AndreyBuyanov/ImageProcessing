#ifndef FILTERSOBEL_HPP
#define FILTERSOBEL_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/ISobel.hpp"

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
    ~filterSobel() override;

    // IFilterUI
    QWidget* GetUI() override { return this; }
    ImageLib::Filters::IFilter* GetFilter() override { return m_Sobel.get(); }
    void ApplyParams() override {}
private:
    Ui::filterSobel *ui;
    std::unique_ptr<ImageLib::Filters::ISobel> m_Sobel;
};

#endif // FILTERSOBEL_HPP
