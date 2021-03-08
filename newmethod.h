#ifndef NEWMETHOD_H
#define NEWMETHOD_H

#include <QDialog>

namespace Ui
{
    class NewMethod;
}

class NewMethod : public QDialog
{
    Q_OBJECT

public:
    explicit NewMethod(QWidget *parent = nullptr);
    ~NewMethod();

private:
    Ui::NewMethod *ui;
};

#endif // NEWMETHOD_H
