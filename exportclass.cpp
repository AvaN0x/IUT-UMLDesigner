#include "exportclass.h"
#include "ui_exportclass.h"

#include <QFileDialog>

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
    QFileDialog *dialog = new QFileDialog(this);
    dialog->setFileMode(QFileDialog::Directory);
    QStringList directoryName;
    if (dialog->exec())
        directoryName = dialog->selectedFiles();

    createClass(QDir(directoryName[0]).filePath(QString::fromStdString(cla->_name)).toUtf8().constData(), *cla, ui->cbx_lang->currentText().toUtf8().constData());
}
