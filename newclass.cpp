#include "newclass.h"
#include "ui_newclass.h"

NewClass::NewClass(QWidget *parent) : QDialog(parent),
                                      ui(new Ui::NewClass)
{
    ui->setupUi(this);
}

NewClass::~NewClass()
{
    delete ui;
}
