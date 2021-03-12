#ifndef NEWCLASS_H
#define NEWCLASS_H

#include <vector>

#include <QDialog>

#include "models/Attribute.hpp"
#include "models/Method.hpp"

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
public slots:
    void handleNewVar(QString, QString, QString, bool, QString, int);
    void handleNewMeth(QString, QString, QString, bool, std::vector<iut_cpp::Argument>, int);
private slots:
    void handleNewAttrClick();
    void handleEditAttrClick();
    void handleDeleteAttrClick();
    void handleNewMethClick();
    void handleEditMethClick();
    void handleDeleteMethClick();

private:
    Ui::NewClass *ui;
    std::vector<iut_cpp::Attribute> *attributes;
    std::vector<iut_cpp::Method> *methods;
};

#endif // NEWCLASS_H
