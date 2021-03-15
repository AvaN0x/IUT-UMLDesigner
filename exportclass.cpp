#include "exportclass.h"
#include "ui_exportclass.h"

#include "models/Utils.hpp"

ExportClass::ExportClass(iut_cpp::Class *clas, QWidget *parent) : QDialog(parent),
                                            ui(new Ui::ExportClass)
{
    ui->setupUi(this);

    cla = clas;

    ui->le_name->setText(QString::fromStdString(clas->_name));
    ui->cbx_lang->addItems(QStringList() << "java");

    connect(this, SIGNAL(accepted()), this, SLOT(handleAccept()));
}

ExportClass::~ExportClass()
{
    delete ui;
}

void ExportClass::handleAccept() {
    //TODO path
    createClass("", *cla, ui->cbx_lang->currentText().toUtf8().constData());
}
