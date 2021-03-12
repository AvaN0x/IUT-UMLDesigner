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

    connect(ui->buttonBox, SIGNAL(accepted()),
            this, SLOT(handleAccept()));
    connect(this, SIGNAL(emitNewMeth(QString, QString, QString, bool, std::vector<iut_cpp::Argument>, int)),
            parent, SLOT(handleNewMeth(QString, QString, QString, bool, std::vector<iut_cpp::Argument>, int)));

    parameters = new std::vector<iut_cpp::Argument>();
}

NewMethod::NewMethod(iut_cpp::Method *meth, int pos, QWidget *parent) : NewMethod(parent)
{
    ui->le_name->setText(QString::fromStdString(meth->_name));
    ui->cbx_return->setCurrentText(QString::fromStdString(meth->_name));
    ui->cbx_visibility->setCurrentText(QString::fromStdString(meth->_status));
    ui->cb_static->setChecked(meth->_isStatic);
    for (auto ptr = meth->_arguments.begin(); ptr != meth->_arguments.end(); ++ptr)
    {
        parameters->push_back(*ptr);
        ui->lv_param->addItem(QString::fromStdString(ptr->_name));
    }
    editPos = pos;
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

void NewMethod::handleEditParam()
{
    NewVar *dialog = new NewVar(&parameters->at(ui->lv_param->currentRow()), ui->lv_param->currentRow(), this);
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
    // TODO const
    iut_cpp::Argument arg(name.toUtf8().constData(), type.toUtf8().constData(), false, defaultValue.toUtf8().constData());
    if (editPos == -1)
    {
        parameters->push_back(arg);
        ui->lv_param->addItem(name);
    }
    else
    {
        parameters->at(editPos) = arg;
        ui->lv_param->item(editPos)->setText(name);
    }
}

void NewMethod::handleAccept()
{
    emit emitNewMeth(ui->le_name->text(), ui->cbx_return->currentText(), ui->cbx_visibility->currentText(), ui->cb_static->isChecked(), *parameters, editPos);
}
