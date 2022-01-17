#ifndef FILTERROBERTS_HPP
#define FILTERROBERTS_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/IRoberts.hpp"

namespace Ui {
class filterRoberts;
}

class filterRoberts :
    public QWidget,
    public IFilterUI
{
    Q_OBJECT

public:
    explicit filterRoberts(QWidget *parent = nullptr);
    ~filterRoberts() override;

    // IFilterUI
    QWidget* GetUI() override { return this; }
    ImageLib::Filters::IFilter* GetFilter() override { return m_Roberts.get(); }
    void ApplyParams() override {}
private:
    Ui::filterRoberts *ui;
    std::unique_ptr<ImageLib::Filters::IRoberts> m_Roberts;
};

#endif // FILTERROBERTS_HPP
