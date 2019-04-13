#ifndef FILTERGAMMA_HPP
#define FILTERGAMMA_HPP

#include <QWidget>

namespace Ui {
class filterGamma;
}

class filterGamma : public QWidget
{
    Q_OBJECT

public:
    explicit filterGamma(QWidget *parent = nullptr);
    ~filterGamma();

private:
    Ui::filterGamma *ui;
};

#endif // FILTERGAMMA_HPP
