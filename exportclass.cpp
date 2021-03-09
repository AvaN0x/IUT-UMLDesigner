#include "exportclass.h"
#include "ui_exportclass.h"

ExportClass::ExportClass(QWidget *parent) : QDialog(parent),
                                            ui(new Ui::ExportClass)
{
    ui->setupUi(this);

    ui->cbx_lang->addItems(QStringList() << "Java");
}

ExportClass::~ExportClass()
{
    delete ui;
}
