#include "newmethod.h"
#include "ui_newmethod.h"

NewMethod::NewMethod(QWidget *parent) : QDialog(parent),
                                        ui(new Ui::NewMethod)
{
    ui->setupUi(this);
}

NewMethod::~NewMethod()
{
    delete ui;
}
