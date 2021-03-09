#ifndef NEWVAR_H
#define NEWVAR_H

#include <QDialog>

namespace Ui
{
    class NewVar;
}

class NewVar : public QDialog
{
    Q_OBJECT

public:
    explicit NewVar(QWidget *parent = nullptr, bool isArg = false);
    ~NewVar();

private:
    Ui::NewVar *ui;
};

#endif // NEWVAR_H
