#include "newvar.h"
#include "ui_newvar.h"

#include "models/types.h"
#include "models/visibility.h"

NewVar::NewVar(QWidget *parent, bool isArg) : QDialog(parent),
                                  ui(new Ui::NewVar)
{
    ui->setupUi(this);

    ui->cbx_type->addItems(*Types::getInstance()->getTypes());

    ui->cbx_visibility->setDisabled(isArg);
    if(!isArg) {
        ui->cbx_visibility->addItems(*Visibility::getInstance()->getVisibility());
    }

    connect(ui->buttonBox, SIGNAL(accepted()),
                this, SLOT(handleAccept()));
    connect(this, SIGNAL(emitNewVar(QString, QString, QString, bool, QString, int)),
            parent, SLOT(handleNewVar(QString, QString, QString, bool, QString, int)));
}

NewVar::NewVar(iut_cpp::Attribute *attr, int pos, QWidget *parent, bool isArg) : NewVar(parent, isArg)
{
    ui->le_name->setText(QString::fromStdString(attr->_name));
    ui->cbx_type->setCurrentText(QString::fromStdString(attr->_type));
    //ui->cbx_visibility->setCurrentText(QString::fromStdString(attr->_visibility));
    ui->cb_static->setChecked(attr->_isStatic);
    ui->le_value->setText(QString::fromStdString(attr->_defaultValue));
    editPos = pos;
}

NewVar::~NewVar()
{
    delete ui;
}

void NewVar::handleAccept() {
    emit emitNewVar(ui->le_name->text(), ui->cbx_type->currentText(), ui->cbx_visibility->currentText(), ui->cb_static->isChecked(), ui->le_value->text(), editPos);
}
