#include "export.h"
#include "ui_export.h"

export::export(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::export)
{
    ui->setupUi(this);
}

export::~export()
{
delete ui;
}
