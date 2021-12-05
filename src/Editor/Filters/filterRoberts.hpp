#ifndef FILTERROBERTS_HPP
#define FILTERROBERTS_HPP

#include <QWidget>
#include <memory>

#include "../IFilterUI.hpp"

#include "ImageLib/Filters/IRoberts.hpp"

using std::unique_ptr;

using ImageLib::Filters::IRoberts;

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
    ~filterRoberts();

    // IFilterUI
    QWidget* GetUI() { return this; }
    IFilter* GetFilter() { return m_Roberts.get(); }
    void ApplyParams() {}
private:
    Ui::filterRoberts *ui;
    unique_ptr<IRoberts> m_Roberts;
};

#endif // FILTERROBERTS_HPP
