#include "newclass.h"
#include "ui_newclass.h"

newclass::newclass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newclass)
{
    ui->setupUi(this);
}

newclass::~newclass()
{
    delete ui;
}
