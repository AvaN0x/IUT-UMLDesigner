#include "newmethod.h"
#include "ui_newmethod.h"

newmethod::newmethod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newmethod)
{
    ui->setupUi(this);
}

newmethod::~newmethod()
{
    delete ui;
}
