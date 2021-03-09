#include "newvar.h"
#include "ui_newvar.h"

#include "types.h"

NewVar::NewVar(QWidget *parent) : QDialog(parent),
                                  ui(new Ui::NewVar)
{
    ui->setupUi(this);

    ui->cbx_type->addItems(*Types::getInstance()->getTypes() + QStringList("Other :"));
}

NewVar::~NewVar()
{
    delete ui;
}
