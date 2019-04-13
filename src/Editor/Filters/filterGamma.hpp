#ifndef FILTERGAMMA_HPP
#define FILTERGAMMA_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/IGamma.hpp"

using std::unique_ptr;

using ImageLib::Filters::IGamma;

namespace Ui {
class filterGamma;
}

class filterGamma :
    public QWidget,
    public IFilterUI
{
    Q_OBJECT

public:
    explicit filterGamma(QWidget *parent = nullptr);
    ~filterGamma();

    // IFilterUI
    QWidget* GetUI() { return this; }
    IFilter* GetFilter() { return m_Gamma.get(); }
    void ApplyParams();
private:
    Ui::filterGamma *ui;
    unique_ptr<IGamma> m_Gamma;
};

#endif // FILTERGAMMA_HPP
