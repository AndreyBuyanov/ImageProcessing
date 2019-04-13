#ifndef FILTERCONVULTION_HPP
#define FILTERCONVULTION_HPP

#include <QWidget>

namespace Ui {
class filterConvultion;
}

class filterConvultion : public QWidget
{
    Q_OBJECT

public:
    explicit filterConvultion(QWidget *parent = nullptr);
    ~filterConvultion();

private:
    Ui::filterConvultion *ui;
};

#endif // FILTERCONVULTION_HPP
