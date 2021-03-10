#include "newmethod.h"
#include "ui_newmethod.h"

#include "newvar.h"
#include "models/types.h"
#include "models/visibility.h"

NewMethod::NewMethod(QWidget *parent) : QDialog(parent),
                                        ui(new Ui::NewMethod)
{
    ui->setupUi(this);

    ui->cbx_return->addItems(QStringList("void") + *Types::getInstance()->getTypes());
    ui->cbx_visibility->addItems(*Visibility::getInstance()->getVisibility());

    connect(ui->btn_newParam, SIGNAL(clicked()),
            this, SLOT(handleNewParam()));
    connect(ui->btn_editParam, SIGNAL(clicked()),
            this, SLOT(handleEditParam()));
    connect(ui->btn_deleteParam, SIGNAL(clicked()),
            this, SLOT(handleRemoveParam()));

    parameters = new std::vector<iut_cpp::Attribute>();
}

NewMethod::~NewMethod()
{
    delete parameters;
    delete ui;
}

void NewMethod::handleNewParam()
{
    NewVar *dialog = new NewVar(this, true);
    dialog->exec();
}

#include <iostream>

void NewMethod::handleEditParam()
{
    NewVar *dialog = new NewVar(&parameters->at(ui->lv_param->currentRow()), ui->lv_param->currentRow(), this, true);
    dialog->exec();
}

void NewMethod::handleRemoveParam()
{
    int currRow = ui->lv_param->currentRow();
    parameters->erase(parameters->begin() + currRow);
    ui->lv_param->takeItem(currRow);
    ui->lv_param->setCurrentRow(currRow);
}

void NewMethod::handleNewVar(QString name, QString type, QString visibilty, bool isStatic, QString defaultValue, int editPos)
{
    //visibilty.toUtf8().constData()
    iut_cpp::Attribute attr(name.toUtf8().constData(), type.toUtf8().constData(), false, isStatic, defaultValue.toUtf8().constData());
    if(editPos == -1) {
        parameters->push_back(attr);
        ui->lv_param->addItem(name);
    }
    else {
        parameters->at(editPos) = attr;
        ui->lv_param->item(editPos)->setText(name);
    }
}
