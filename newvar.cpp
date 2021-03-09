#include "newvar.h"
#include "ui_newvar.h"

#include "models/types.h"
#include "models/visibility.h"

NewVar::NewVar(QWidget *parent, bool isArg) : QDialog(parent),
                                  ui(new Ui::NewVar)
{
    ui->setupUi(this);

    ui->cbx_type->addItems(*Types::getInstance()->getTypes() + QStringList("Other :"));

    ui->cbx_visibility->setDisabled(isArg);
    if(!isArg) {
        ui->cbx_visibility->addItems(*Visibility::getInstance()->getVisibility());
    }
}

NewVar::~NewVar()
{
    delete ui;
}
