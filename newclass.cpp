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

    connect(ui->btnbx, SIGNAL(accepted()),
            this, SLOT(handleAccept()));
    connect(this, SIGNAL(emitNewClass(QString, std::vector<iut_cpp::Attribute>, bool, bool, std::vector<iut_cpp::Method>, int)),
            parent, SLOT(handleNewClass(QString, std::vector<iut_cpp::Attribute>, bool, bool, std::vector<iut_cpp::Method>, int)));

    attributes = new std::vector<iut_cpp::Attribute>();
    methods = new std::vector<iut_cpp::Method>();
}

NewClass::NewClass(iut_cpp::Class clas, int pos, QWidget *parent) : NewClass(parent)
{
    //TODO
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
    ui->lv_attr->setCurrentRow(currRow);
}

void NewClass::handleNewVar(QString name, QString type, QString visibilty, bool isStatic, QString defaultValue, int editPos)
{
    //TODO const
    iut_cpp::Attribute attr(name.toUtf8().constData(), type.toUtf8().constData(), visibilty.toUtf8().constData(), isStatic, false, defaultValue.toUtf8().constData());
    if (editPos == -1)
    {
        attributes->push_back(attr);
        ui->lv_attr->addItem(name);
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
    ui->lv_meth->setCurrentRow(currRow);
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
        ui->lv_meth->addItem(name);
    }
    else
    {
        methods->at(editPos) = meth;
        ui->lv_meth->item(editPos)->setText(name);
    }
}

void NewClass::handleAccept()
{
    emit emitNewClass(ui->le_name->text(), *attributes, ui->cb_public->isChecked(), ui->cb_abstract->isChecked(), *methods, editPos);
    close(); // Why I need to close the window here and not at other handle ? Dunno
}
