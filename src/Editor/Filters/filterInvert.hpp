#ifndef FILTERINVERT_HPP
#define FILTERINVERT_HPP

#include <QWidget>

namespace Ui {
class filterInvert;
}

class filterInvert : public QWidget
{
    Q_OBJECT

public:
    explicit filterInvert(QWidget *parent = nullptr);
    ~filterInvert();

private:
    Ui::filterInvert *ui;
};

#endif // FILTERINVERT_HPP
