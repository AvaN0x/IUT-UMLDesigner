#ifndef NEWVAR_H
#define NEWVAR_H

#include <QDialog>

namespace Ui {
class newvar;
}

class newvar : public QDialog
{
    Q_OBJECT

public:
    explicit newvar(QWidget *parent = nullptr);
    ~newvar();

private:
    Ui::newvar *ui;
};

#endif // NEWVAR_H
