#ifndef FILTERGAMMA_HPP
#define FILTERGAMMA_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/IGamma.hpp"

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
    ~filterGamma() override;

    // IFilterUI
    QWidget* GetUI() override { return this; }
    ImageLib::Filters::IFilter* GetFilter() override { return m_Gamma.get(); }
    void ApplyParams() override;
private:
    Ui::filterGamma *ui;
    std::unique_ptr<ImageLib::Filters::IGamma> m_Gamma;
};

#endif // FILTERGAMMA_HPP
