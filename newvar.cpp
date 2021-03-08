#include "newvar.h"
#include "ui_newvar.h"

NewVar::NewVar(QWidget *parent) : QDialog(parent),
                                  ui(new Ui::NewVar)
{
    ui->setupUi(this);
}

NewVar::~NewVar()
{
    delete ui;
}
