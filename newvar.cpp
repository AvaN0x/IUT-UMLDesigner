#include "newvar.h"
#include "ui_newvar.h"

#include "models/types.h"
#include "models/visibility.h"
#include "models/Utils.hpp"

NewVar::NewVar(QWidget *parent, bool isArg) : QDialog(parent),
                                              ui(new Ui::NewVar)
{
    ui->setupUi(this);

    ui->cbx_type->addItems(*Types::getInstance()->getTypes());

    ui->cbx_visibility->setDisabled(isArg);
    ui->cb_static->setDisabled(isArg);
    if (!isArg)
    {
        ui->cbx_visibility->addItems(*Visibility::getInstance()->getVisibility());
    }

    connect(ui->buttonBox, SIGNAL(accepted()),
            this, SLOT(handleAccept()));
    connect(this, SIGNAL(emitNewVar(QString, QString, QString, bool, QString, int)),
            parent, SLOT(handleNewVar(QString, QString, QString, bool, QString, int)));
}

NewVar::NewVar(iut_cpp::Attribute *attr, int pos, QWidget *parent) : NewVar(parent, false)
{
    ui->le_name->setText(QString::fromStdString(attr->_name));
    ui->cbx_type->setCurrentText(QString::fromStdString(attr->_type));
    ui->cbx_visibility->setCurrentText(QString::fromStdString(attr->_status));
    ui->cb_static->setChecked(attr->_isStatic);
    ui->le_value->setText(QString::fromStdString(attr->_defaultValue));
    editPos = pos;
}

NewVar::NewVar(iut_cpp::Argument *attr, int pos, QWidget *parent) : NewVar(parent, true)
{
    ui->le_name->setText(QString::fromStdString(attr->_name));
    ui->cbx_type->setCurrentText(QString::fromStdString(attr->_type));
    ui->le_value->setText(QString::fromStdString(attr->_defaultValue));
    editPos = pos;
}

NewVar::~NewVar()
{
    delete ui;
}

void NewVar::handleAccept()
{
    std::string name = remSpaces(ui->le_name->text().toUtf8().constData());
    std::string value = remSpaces(ui->le_value->text().toUtf8().constData());

    // don't check value, because you can have an empty default value
    if (!empty(name))
        // TODO maybe prevent from closing ?
        emit emitNewVar(QString::fromUtf8(name), ui->cbx_type->currentText(), ui->cbx_visibility->currentText(), ui->cb_static->isChecked(), QString::fromUtf8(value), editPos);
    else
    {
        //TODO alert
    }
}
