#include "newclass.h"
#include "ui_newclass.h"

#include "newvar.h"
#include "newmethod.h"

#include "models/types.h"

NewClass::NewClass(QWidget *parent) : QDialog(parent),
                                      ui(new Ui::NewClass)
{
    ui->setupUi(this);

    ui->cbx_template->addItems(QStringList("") + *Types::getInstance()->getTypes() + QStringList("Other :"));

    connect(ui->btn_newAttr, SIGNAL(clicked()),
            this, SLOT(handleNewAttrClick()));
    connect(ui->btn_editAttr, SIGNAL(clicked()),
            this, SLOT(handleEditAttrClick()));
    connect(ui->btn_deleteAttr, SIGNAL(clicked()),
            this, SLOT(handleDeleteAttrClick()));

    connect(ui->btn_newMeth, SIGNAL(clicked()),
            this, SLOT(handleNewMethClick()));
    connect(ui->btn_editMeth, SIGNAL(clicked()),
            this, SLOT(handleEditMethClick()));
    connect(ui->btn_deleteMeth, SIGNAL(clicked()),
            this, SLOT(handleDeleteMethClick()));

    attributes = new std::vector<iut_cpp::Attribute>();
}

NewClass::~NewClass()
{
    delete ui;
}

void NewClass::handleNewAttrClick()
{
    NewVar *dialog = new NewVar(this);
    dialog->exec();
}

void NewClass::handleEditAttrClick()
{
    NewVar *dialog = new NewVar(&attributes->at(ui->lv_attr->currentRow()), ui->lv_attr->currentRow(), this, true);
    dialog->exec();
}

void NewClass::handleDeleteAttrClick()
{
    int currRow = ui->lv_attr->currentRow();
    attributes->erase(attributes->begin() + currRow);
    ui->lv_attr->takeItem(currRow);
    ui->lv_attr->setCurrentRow(currRow);
}

void NewClass::handleNewVar(QString name, QString type, QString visibilty, bool isStatic, QString defaultValue, int editPos)
{
    //visibilty.toUtf8().constData()
    iut_cpp::Attribute attr(name.toUtf8().constData(), type.toUtf8().constData(), false, isStatic, defaultValue.toUtf8().constData());
    if(editPos == -1) {
        attributes->push_back(attr);
        ui->lv_attr->addItem(name);
    }
    else {
        attributes->at(editPos) = attr;
        ui->lv_attr->item(editPos)->setText(name);
    }
}

void NewClass::handleNewMethClick()
{
    NewMethod *dialog = new NewMethod(this);
    dialog->show();
}

void NewClass::handleEditMethClick()
{
    //TODO
}

void NewClass::handleDeleteMethClick()
{
    //TODO
}

