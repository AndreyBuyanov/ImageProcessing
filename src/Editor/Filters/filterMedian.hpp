#ifndef FILTERMEDIAN_HPP
#define FILTERMEDIAN_HPP

#include <QWidget>

namespace Ui {
class filterMedian;
}

class filterMedian : public QWidget
{
    Q_OBJECT

public:
    explicit filterMedian(QWidget *parent = nullptr);
    ~filterMedian();

private:
    Ui::filterMedian *ui;
};

#endif // FILTERMEDIAN_HPP
