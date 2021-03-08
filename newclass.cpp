#include "newclass.h"
#include "ui_newclass.h"

#include "newvar.h"
#include "newmethod.h"

NewClass::NewClass(QWidget *parent) : QDialog(parent),
                                      ui(new Ui::NewClass)
{
    ui->setupUi(this);

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
            parent, SLOT(handleNewClass()));
}

NewClass::~NewClass()
{
    delete ui;
}


void NewClass::handleNewAttrClick(){
    NewVar *dialog = new NewVar(this);
    dialog->exec();
}

void NewClass::handleEditAttrClick(){
    //TODO
}

void NewClass::handleDeleteAttrClick(){
    //TODO
}

void NewClass::handleNewMethClick(){
    NewMethod *dialog = new NewMethod(this);
    dialog->show();
}

void NewClass::handleEditMethClick(){
    //TODO
}

void NewClass::handleDeleteMethClick(){
    //TODO
}
