#ifndef FILTERGRAYSCALE_HPP
#define FILTERGRAYSCALE_HPP

#include <QWidget>

namespace Ui {
class filterGrayscale;
}

class filterGrayscale : public QWidget
{
    Q_OBJECT

public:
    explicit filterGrayscale(QWidget *parent = nullptr);
    ~filterGrayscale();

private:
    Ui::filterGrayscale *ui;
};

#endif // FILTERGRAYSCALE_HPP
