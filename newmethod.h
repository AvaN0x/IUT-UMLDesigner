#ifndef NEWMETHOD_H
#define NEWMETHOD_H

#include <vector>

#include <QDialog>
#include <QStringList>

#include "models/List.hpp"
#include "models/Argument.hpp"
#include "models/Method.hpp"

namespace Ui
{
    class NewMethod;
}

class NewMethod : public QDialog
{
    Q_OBJECT

public:
    explicit NewMethod(QWidget *parent = nullptr);
    explicit NewMethod(iut_cpp::Method *meth, int pos, QWidget *parent = nullptr);
    ~NewMethod();
signals:
    void emitNewMeth(QString, QString, QString, bool, std::vector<iut_cpp::Argument>, int);
public slots:
    void handleNewVar(QString, QString, QString, bool, QString, int);
private slots:
    void handleNewParam();
    void handleEditParam();
    void handleRemoveParam();
    void handleAccept();
private:
    Ui::NewMethod *ui;
    std::vector<iut_cpp::Argument> *parameters;
    int editPos = -1;
};

#endif // NEWMETHOD_H
