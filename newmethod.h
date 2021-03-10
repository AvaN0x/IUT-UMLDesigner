#ifndef NEWMETHOD_H
#define NEWMETHOD_H

#include <vector>

#include <QDialog>
#include <QStringList>

#include "models/List.hpp"
#include "models/Attribute.hpp"

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
public slots:
    void handleNewVar(QString, QString, QString, bool, QString, int);
private slots:
    void handleNewParam();
    void handleEditParam();
    void handleRemoveParam();
private:
    Ui::NewMethod *ui;
    std::vector<iut_cpp::Attribute> *parameters;
};

#endif // NEWMETHOD_H
