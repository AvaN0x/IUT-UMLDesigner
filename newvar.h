#ifndef NEWVAR_H
#define NEWVAR_H

#include <QDialog>

#include "models/Attribute.hpp"

namespace Ui
{
    class NewVar;
}

class NewVar : public QDialog
{
    Q_OBJECT

public:
    explicit NewVar(QWidget *parent = nullptr, bool isArg = false);
    explicit NewVar(iut_cpp::Attribute *attr, int pos, QWidget *parent = nullptr, bool isArg = false);
    ~NewVar();
signals:
    void emitNewVar(QString, QString, QString, bool, QString, int);
private slots:
    void handleAccept();
private:
    Ui::NewVar *ui;
    int editPos = -1;
};

#endif // NEWVAR_H
