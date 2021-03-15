#ifndef EXPORTCLASS_H
#define EXPORTCLASS_H

#include <QDialog>

#include "models/Class.hpp"

namespace Ui
{
    class ExportClass;
}

class ExportClass : public QDialog
{
    Q_OBJECT

public:
    explicit ExportClass(iut_cpp::Class *clas, QWidget *parent = nullptr);
    ~ExportClass();
private slots:
    void handleAccept();
private:
    Ui::ExportClass *ui;
    iut_cpp::Class *cla;
};

#endif // EXPORTCLASS_H
