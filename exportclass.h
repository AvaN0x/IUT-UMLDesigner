#ifndef EXPORTCLASS_H
#define EXPORTCLASS_H

#include <QDialog>

namespace Ui
{
    class ExportClass;
}

class ExportClass : public QDialog
{
    Q_OBJECT

public:
    explicit ExportClass(QWidget *parent = nullptr);
    ~ExportClass();

private:
    Ui::ExportClass *ui;
};

#endif // EXPORTCLASS_H
