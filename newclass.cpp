#include "newclass.h"
#include "ui_newclass.h"

#include <QMessageBox>

#include "newvar.h"
#include "newmethod.h"

#include "models/types.h"
#include "models/Utils.hpp"

NewClass::NewClass(QWidget *parent) : QDialog(parent),
                                      ui(new Ui::NewClass)
{
    ui->setupUi(this);
    ui->le_name->setFocus();

    connect(ui->lv_attr, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(handleAttrClick(QListWidgetItem*)));
    connect(ui->btn_newAttr, SIGNAL(clicked()),
            this, SLOT(handleNewAttrClick()));
    connect(ui->btn_editAttr, SIGNAL(clicked()),
            this, SLOT(handleEditAttrClick()));
    ui->btn_editAttr->setDisabled(true);
    connect(ui->btn_deleteAttr, SIGNAL(clicked()),
            this, SLOT(handleDeleteAttrClick()));
    ui->btn_deleteAttr->setDisabled(true);

    connect(ui->lv_meth, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(handleMethClick(QListWidgetItem*)));
    connect(ui->btn_newMeth, SIGNAL(clicked()),
            this, SLOT(handleNewMethClick()));
    connect(ui->btn_editMeth, SIGNAL(clicked()),
            this, SLOT(handleEditMethClick()));
    ui->btn_editMeth->setDisabled(true);
    connect(ui->btn_deleteMeth, SIGNAL(clicked()),
            this, SLOT(handleDeleteMethClick()));
    ui->btn_deleteMeth->setDisabled(true);

    connect(ui->btnbx, SIGNAL(accepted()), this, SLOT(handleAccept()));
    connect(ui->btnbx, SIGNAL(rejected()), this, SLOT(reject()));
    connect(this, SIGNAL(emitNewClass(QString, QString, std::vector<iut_cpp::Attribute>, bool, bool, std::vector<iut_cpp::Method>, int)),
            parent, SLOT(handleNewClass(QString, QString, std::vector<iut_cpp::Attribute>, bool, bool, std::vector<iut_cpp::Method>, int)));

    attributes = new std::vector<iut_cpp::Attribute>();
    methods = new std::vector<iut_cpp::Method>();
}

NewClass::NewClass(iut_cpp::Class *clas, int pos, QWidget *parent) : NewClass(parent)
{
    ui->le_name->setText(QString::fromStdString(clas->_name));
    ui->cb_public->setChecked(clas->_isPublic);
    ui->cb_abstract->setChecked(clas->_isAbstract);
    ui->le_template->setText(QString::fromStdString(clas->_templates));
    for (auto ptr = clas->_attributes.begin(); ptr != clas->_attributes.end(); ++ptr)
    {
        attributes->push_back(*ptr);
        ui->lv_attr->addItem(QString::fromStdString(ptr->toString()));
    }
    for (auto ptr = clas->_methods.begin(); ptr != clas->_methods.end(); ++ptr)
    {
        methods->push_back(*ptr);
        ui->lv_meth->addItem(QString::fromStdString(ptr->toString()));
    }
    editPos = pos;
}

NewClass::~NewClass()
{
    delete attributes;
    delete methods;
    delete ui;
}

void NewClass::handleNewAttrClick()
{
    NewVar *dialog = new NewVar(this);
    dialog->exec();
}

void NewClass::handleEditAttrClick()
{
    NewVar *dialog = new NewVar(&attributes->at(ui->lv_attr->currentRow()), ui->lv_attr->currentRow(), this);
    dialog->exec();
}

void NewClass::handleDeleteAttrClick()
{
    int currRow = ui->lv_attr->currentRow();
    attributes->erase(attributes->begin() + currRow);
    ui->lv_attr->takeItem(currRow);
    ui->lv_attr->setCurrentRow(-1);
    ui->btn_editAttr->setDisabled(true);
    ui->btn_deleteAttr->setDisabled(true);
}

void NewClass::handleNewVar(QString name, QString type, QString visibilty, bool isStatic, bool isConst, QString defaultValue, int editPos)
{
    iut_cpp::Attribute attr(name.toUtf8().constData(), type.toUtf8().constData(), visibilty.toUtf8().constData(), isStatic, isConst, defaultValue.toUtf8().constData());
    if (editPos == -1)
    {
        attributes->push_back(attr);
        ui->lv_attr->addItem(QString::fromStdString(attr.toString()));
    }
    else
    {
        attributes->at(editPos) = attr;
        ui->lv_attr->item(editPos)->setText(name);
    }
}

void NewClass::handleNewMethClick()
{
    NewMethod *dialog = new NewMethod(this);
    dialog->exec();
}

void NewClass::handleEditMethClick()
{
    NewMethod *dialog = new NewMethod(&methods->at(ui->lv_meth->currentRow()), ui->lv_meth->currentRow(), this);
    dialog->exec();
}

void NewClass::handleDeleteMethClick()
{
    int currRow = ui->lv_meth->currentRow();
    methods->erase(methods->begin() + currRow);
    ui->lv_meth->takeItem(currRow);
    ui->lv_meth->setCurrentRow(-1);
    ui->btn_editMeth->setDisabled(true);
    ui->btn_deleteMeth->setDisabled(true);
}

void NewClass::handleNewMeth(QString name, QString ret, QString visibilty, bool isStatic, std::vector<iut_cpp::Argument> arguments, int editPos)
{
    iut_cpp::List<iut_cpp::Argument> args;
    foreach (iut_cpp::Argument arg, arguments)
    {
        args.push_last(arg);
    }
    iut_cpp::Method meth(name.toUtf8().constData(), ret.toUtf8().constData(), visibilty.toUtf8().constData(), isStatic, args);
    if (editPos == -1)
    {
        methods->push_back(meth);
        ui->lv_meth->addItem(QString::fromStdString(meth.toString()));
    }
    else
    {
        methods->at(editPos) = meth;
        ui->lv_meth->item(editPos)->setText(name);
    }
}

void NewClass::handleAccept()
{
    std::string name = remSpaces(ui->le_name->text().toUtf8().constData());
    std::string templ = remSpaces(ui->le_template->text().toUtf8().constData());

    if (!empty(name))
    {
        emit emitNewClass(QString::fromStdString(name), QString::fromStdString(templ), *attributes, ui->cb_public->isChecked(), ui->cb_abstract->isChecked(), *methods, editPos);
        close();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Name can't be empty !");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
}

void NewClass::handleAttrClick(QListWidgetItem* item){
    ui->btn_editAttr->setDisabled(false);
    ui->btn_deleteAttr->setDisabled(false);
}

void NewClass::handleMethClick(QListWidgetItem* item){
    ui->btn_editMeth->setDisabled(false);
    ui->btn_deleteMeth->setDisabled(false);
}
