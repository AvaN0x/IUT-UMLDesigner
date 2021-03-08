#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "newclass.h"
#include "exportclass.h"

#include "Class.hpp"
#include "Attribute.hpp"
#include "List.hpp"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_newClass, SIGNAL(clicked()),
            this, SLOT(handleNewClick()));
    connect(ui->btn_save, SIGNAL(clicked()),
            this, SLOT(handleSaveClick()));
    connect(ui->btn_saveto, SIGNAL(clicked()),
            this, SLOT(handleSaveToClick()));
    connect(ui->btn_export, SIGNAL(clicked()),
            this, SLOT(handleExportClick()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleNewClick()
{
    NewClass *dialog = new NewClass(this);
    dialog->exec();
}

void MainWindow::handleOpenClick()
{
    QFileDialog *dialog = new QFileDialog(this);
    dialog->setFileMode(QFileDialog::ExistingFile);
    QStringList directoryName;
    if (dialog->exec())
        directoryName = dialog->selectedFiles();
    //TODO Unserialize
}

void MainWindow::handleSaveClick()
{
    if (savePath.length() > 0)
    {
        saveFile();
    }
    else
    {
        this->handleSaveToClick();
    }
}

void MainWindow::handleSaveToClick()
{
    QFileDialog *dialog = new QFileDialog(this);
    dialog->setFileMode(QFileDialog::Directory);
    QStringList directoryName;
    if (dialog->exec())
        directoryName = dialog->selectedFiles();
    //TODO Get the real path
    saveFile();
}

void MainWindow::handleExportClick()
{
    ExportClass *dialog = new ExportClass(this);
    dialog->exec();
}

void MainWindow::saveFile()
{
    //TODO Serialize
}

void MainWindow::handleNewClass(const QString name, const QStringList attr, const bool isPublic, const bool isAbstr)
{
    iut_cpp::List<iut_cpp::Attribute> q;
    //TODO attr to Queue
    iut_cpp::Class myClass(name.toUtf8().constData(), q, isPublic, isAbstr);
    //TODO Show in window
}
