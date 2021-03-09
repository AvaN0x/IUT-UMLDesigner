#ifndef NEWCLASS_H
#define NEWCLASS_H

#include <QDialog>

namespace Ui
{
    class NewClass;
}

class NewClass : public QDialog
{
    Q_OBJECT

public:
    explicit NewClass(QWidget *parent = nullptr);
    ~NewClass();
private slots:
    void handleNewAttrClick();
    void handleEditAttrClick();
    void handleDeleteAttrClick();
    void handleNewMethClick();
    void handleEditMethClick();
    void handleDeleteMethClick();
    void handleTemplateChanged(int);
private:
    Ui::NewClass *ui;
};

#endif // NEWCLASS_H
