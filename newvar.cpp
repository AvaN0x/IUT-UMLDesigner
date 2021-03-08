#include "newvar.h"
#include "ui_newvar.h"

newvar::newvar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newvar)
{
    ui->setupUi(this);
}

newvar::~newvar()
{
    delete ui;
}
