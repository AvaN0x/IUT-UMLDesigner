#include "exportclass.h"
#include "ui_exportclass.h"

ExportClass::ExportClass(QWidget *parent) : QDialog(parent),
                                            ui(new Ui::ExportClass)
{
    ui->setupUi(this);
}

ExportClass::~ExportClass()
{
    delete ui;
}
