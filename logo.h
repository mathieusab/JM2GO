#ifndef LOGO_H
#define LOGO_H

#include <QWidget>

namespace Ui {
class Logo;
}

class Logo : public QWidget
{
    Q_OBJECT

public:
    explicit Logo(QWidget *parent = 0);
    ~Logo();

private:
    Ui::Logo *ui;
};

#endif // LOGO_H
