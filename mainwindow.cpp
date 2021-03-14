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
    connect(ui->btn_export, SIGNAL(clicked()),
            this, SLOT(handleExportClick()));

    classes = new std::vector<iut_cpp::Class>();
}

MainWindow::~MainWindow()
{
    delete classes;
    delete ui;
}

void MainWindow::handleNewClick()
{
    NewClass *dialog = new NewClass(this);
    dialog->exec();
}

void MainWindow::handleExportClick()
{
    ExportClass *dialog = new ExportClass(this);
    dialog->exec();
}

void MainWindow::handleNewClass(QString name, QString templ, std::vector<iut_cpp::Attribute> attrs, bool isPublic, bool isAbstr, std::vector<iut_cpp::Method> meths, int editPos)
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

    iut_cpp::Class cla(name.toUtf8().constData(), templ.toUtf8().constData(), attributes, isPublic, isAbstr, methods);
    if (editPos == -1)
    {
        classes->push_back(cla);
        // TODO Add class to UI
    }
    else
    {
        classes->at(editPos) = cla;
        // TODO Edit class to UI
    }

    createClass("", cla, "java");
}
