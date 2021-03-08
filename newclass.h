#ifndef NEWCLASS_H
#define NEWCLASS_H

#include <QDialog>

namespace Ui {
class newclass;
}

class newclass : public QDialog
{
    Q_OBJECT

public:
    explicit newclass(QWidget *parent = nullptr);
    ~newclass();

private:
    Ui::newclass *ui;
};

#endif // NEWCLASS_H
