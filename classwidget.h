#ifndef CLASSWIDGET_H
#define CLASSWIDGET_H

#include <QWidget>

#include "models/Class.hpp"

namespace Ui {
class ClassWidget;
}

class ClassWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClassWidget(iut_cpp::Class *clas, QWidget *parent = nullptr);
    ~ClassWidget();
    void display(iut_cpp::Class *);

private:
    Ui::ClassWidget *ui;
};

#endif // CLASSWIDGET_H
