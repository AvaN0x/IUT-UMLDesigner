#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "newclass.h"
#include "exportclass.h"

#include "models/Utils.hpp"
#include "models/Class.hpp"
#include "models/Attribute.hpp"
#include "models/List.hpp"

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

// TODO: REMOVE
#include <iostream>

void MainWindow::handleNewClass(QString name, std::vector<iut_cpp::Attribute> attrs, bool isPublic, bool isAbstr, std::vector<iut_cpp::Method> meths, int editPos)
{
    iut_cpp::List<iut_cpp::Attribute> attributes;
    foreach (iut_cpp::Attribute arg, attrs)
    {
        attributes.push_last(arg);
    }
    iut_cpp::List<iut_cpp::Method> methods;
    foreach (iut_cpp::Method arg, meths)
    {
        methods.push_last(arg);
    }
    iut_cpp::Class cla(name.toUtf8().constData(), attributes, isPublic, isAbstr, methods);
    if (editPos == -1)
    {
    }
    else
    {
    }

    //TODO: REMOVE
    // std::cout << cla.toJava() << std::endl;
    createClass("", cla, "java");
}
