#ifndef FILTERGRAYSCALE_HPP
#define FILTERGRAYSCALE_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/IGrayscale.hpp"

namespace Ui {
class filterGrayscale;
}

class filterGrayscale :
    public QWidget,
    public IFilterUI
{
    Q_OBJECT

public:
    explicit filterGrayscale(QWidget *parent = nullptr);
    ~filterGrayscale() override;

    // IFilterUI
    QWidget* GetUI() override { return this; }
    ImageLib::Filters::IFilter* GetFilter() override { return m_Grayscale.get(); }
    void ApplyParams() override {}
private:
    Ui::filterGrayscale *ui;
    std::unique_ptr<ImageLib::Filters::IGrayscale> m_Grayscale;
};

#endif // FILTERGRAYSCALE_HPP
