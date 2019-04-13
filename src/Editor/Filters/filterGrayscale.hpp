#ifndef FILTERGRAYSCALE_HPP
#define FILTERGRAYSCALE_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/IGrayscale.hpp"

using std::unique_ptr;

using ImageLib::Filters::IGrayscale;

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
    ~filterGrayscale();

    // IFilterUI
    QWidget* GetUI() { return this; }
    IFilter* GetFilter() { return m_Grayscale.get(); }
    void ApplyParams() {}
private:
    Ui::filterGrayscale *ui;
    unique_ptr<IGrayscale> m_Grayscale;
};

#endif // FILTERGRAYSCALE_HPP
