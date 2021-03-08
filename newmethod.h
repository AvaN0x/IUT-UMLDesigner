#ifndef NEWMETHOD_H
#define NEWMETHOD_H

#include <QDialog>

namespace Ui {
class newmethod;
}

class newmethod : public QDialog
{
    Q_OBJECT

public:
    explicit newmethod(QWidget *parent = nullptr);
    ~newmethod();

private:
    Ui::newmethod *ui;
};

#endif // NEWMETHOD_H
