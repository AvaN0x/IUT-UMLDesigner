#include "classwidget.h"
#include "ui_classwidget.h"

ClassWidget::ClassWidget(iut_cpp::Class *clas, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassWidget)
{
    ui->setupUi(this);
    display(clas);
}

ClassWidget::~ClassWidget()
{
    delete ui;
}

void ClassWidget::display(iut_cpp::Class *clas) {
    ui->lbl_name->setText(QString::fromStdString(clas->toString()));
    ui->lw_attrs->clear();
    for (auto ptr = clas->_attributes.begin(); ptr != clas->_attributes.end(); ++ptr)
    {
        ui->lw_attrs->addItem(QString::fromStdString(ptr->toString()));
    }
    ui->lw_meths->clear();
    for (auto ptr = clas->_methods.begin(); ptr != clas->_methods.end(); ++ptr)
    {
        ui->lw_meths->addItem(QString::fromStdString(ptr->toString()));
    }
}
