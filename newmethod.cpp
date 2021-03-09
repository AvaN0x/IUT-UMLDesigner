#include "newmethod.h"
#include "ui_newmethod.h"

#include "newvar.h"
#include "models/types.h"
#include "models/visibility.h"

NewMethod::NewMethod(QWidget *parent) : QDialog(parent),
                                        ui(new Ui::NewMethod)
{
    ui->setupUi(this);

    ui->cbx_return->addItems(QStringList("void") + *Types::getInstance()->getTypes() + QStringList("Other :"));
    ui->cbx_visibility->addItems(*Visibility::getInstance()->getVisibility());

    connect(ui->btn_newParam, SIGNAL(clicked()),
            this, SLOT(handleNewParam()));
    connect(ui->btn_editParam, SIGNAL(clicked()),
            this, SLOT(handleEditParam()));
    connect(ui->btn_deleteParam, SIGNAL(clicked()),
            this, SLOT(handleRemoveParam()));
}

NewMethod::~NewMethod()
{
    delete ui;
}

void NewMethod::handleNewParam()
{
    NewVar *dialog = new NewVar(this, true);
    dialog->exec();
}

void NewMethod::handleEditParam()
{
    //TODO
}

void NewMethod::handleRemoveParam()
{
    //TODO
}
