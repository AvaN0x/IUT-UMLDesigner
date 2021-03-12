#ifndef NEWCLASS_H
#define NEWCLASS_H

#include <vector>

#include <QDialog>

#include "models/Class.hpp"
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
    explicit NewClass(iut_cpp::Class clas, int pos, QWidget *parent = nullptr);
    ~NewClass();
signals:
    void emitNewClass(QString, std::vector<iut_cpp::Attribute>, bool, bool, std::vector<iut_cpp::Method>, int);
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
    void handleAccept();

private:
    Ui::NewClass *ui;
    std::vector<iut_cpp::Attribute> *attributes;
    std::vector<iut_cpp::Method> *methods;
    int editPos = -1;
};

#endif // NEWCLASS_H
