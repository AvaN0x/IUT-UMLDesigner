#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "newclass.h"
#include "exportclass.h"

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

void MainWindow::handleNewClick() {
    NewClass *dialog = new NewClass(this);
    dialog->show();
}

void MainWindow::handleSaveClick() {
    //TODO
}

void MainWindow::handleSaveToClick() {
    //TODO
}

void MainWindow::handleExportClick(){
    ExportClass *dialog = new ExportClass(this);
    dialog->show();
}
