#include "newmethod.h"
#include "ui_newmethod.h"

#include <QMessageBox>

#include "newvar.h"

#include "models/types.h"
#include "models/visibility.h"
#include "models/Utils.hpp"

NewMethod::NewMethod(QWidget *parent) : QDialog(parent),
                                        ui(new Ui::NewMethod)
{
    ui->setupUi(this);

    ui->cbx_return->addItems(QStringList("void") + *Types::getInstance()->getTypes());
    ui->cbx_visibility->addItems(*Visibility::getInstance()->getVisibility());

    connect(ui->lv_param, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(handleParamClick(QListWidgetItem*)));
    ui->btn_editParam->setDisabled(true);

    connect(ui->btn_newParam, SIGNAL(clicked()),
            this, SLOT(handleNewParam()));
    connect(ui->btn_editParam, SIGNAL(clicked()),
            this, SLOT(handleEditParam()));
    connect(ui->btn_deleteParam, SIGNAL(clicked()),
            this, SLOT(handleRemoveParam()));

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(handleAccept()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    connect(this, SIGNAL(emitNewMeth(QString, QString, QString, bool, std::vector<iut_cpp::Argument>, int)),
            parent, SLOT(handleNewMeth(QString, QString, QString, bool, std::vector<iut_cpp::Argument>, int)));

    parameters = new std::vector<iut_cpp::Argument>();
}

NewMethod::NewMethod(iut_cpp::Method *meth, int pos, QWidget *parent) : NewMethod(parent)
{
    ui->le_name->setText(QString::fromStdString(meth->_name));
    ui->cbx_return->setCurrentText(QString::fromStdString(meth->_returnType));
    ui->cbx_visibility->setCurrentText(QString::fromStdString(meth->_status));
    ui->cb_static->setChecked(meth->_isStatic);
    for (auto ptr = meth->_arguments.begin(); ptr != meth->_arguments.end(); ++ptr)
    {
        parameters->push_back(*ptr);
        ui->lv_param->addItem(QString::fromStdString(ptr->toString()));
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
    ui->lv_param->setCurrentRow(-1);
    ui->btn_editParam->setDisabled(true);
}

void NewMethod::handleNewVar(QString name, QString type, QString visibilty, bool isStatic, bool isConst, QString defaultValue, int editPos)
{
    iut_cpp::Argument arg(name.toUtf8().constData(), type.toUtf8().constData(), isConst, defaultValue.toUtf8().constData());
    if (editPos == -1)
    {
        parameters->push_back(arg);
        ui->lv_param->addItem(QString::fromUtf8(arg.toString()));
    }
    else
    {
        parameters->at(editPos) = arg;
        ui->lv_param->item(editPos)->setText(name);
    }
}

void NewMethod::handleAccept()
{
    std::string name = remSpaces(ui->le_name->text().toUtf8().constData());

    if (!empty(name)) {
        emit emitNewMeth(QString::fromUtf8(name), ui->cbx_return->currentText(), ui->cbx_visibility->currentText(), ui->cb_static->isChecked(), *parameters, editPos);
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

void NewMethod::handleParamClick(QListWidgetItem*){
    ui->btn_editParam->setDisabled(false);
}
