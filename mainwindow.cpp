#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "newclass.h"
#include "exportclass.h"
#include "classwidget.h"

#include "models/Utils.hpp"
#include "models/Class.hpp"
#include "models/Attribute.hpp"
#include "models/List.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_newClass, SIGNAL(clicked()),
            this, SLOT(handleNewClick()));

    classes = new std::vector<iut_cpp::Class>();
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < ui->sw_classes->count() ; i++) {
        delete ui->sw_classes->itemAt(i)->widget();
    }
    delete classes;
    delete ui;
}

void MainWindow::handleNewClick()
{
    NewClass *dialog = new NewClass(this);
    dialog->exec();
}

void MainWindow::handleEditClass() {
    NewClass *dialog = new NewClass(&classes->at(classToExport), classToExport, this);
    dialog->exec();
}

void MainWindow::handleExportClick()
{
    if(classToExport != -1) {
        ExportClass *dialog = new ExportClass(&classes->at(classToExport), this);
        dialog->exec();
    }
}

void MainWindow::handleNewClass(QString name, QString templ, std::vector<iut_cpp::Attribute> attrs, bool isPublic, bool isAbstr, std::vector<iut_cpp::Method> meths, int editPos)
{
    iut_cpp::List<iut_cpp::Attribute> attributes;
    foreach (iut_cpp::Attribute arg, attrs)
    {
        attributes.push_last(arg);
    }
    iut_cpp::List<iut_cpp::Method> methods;
    foreach (iut_cpp::Method meth, meths)
    {
        methods.push_last(meth);
    }
    iut_cpp::Class cla(name.toUtf8().constData(), templ.toUtf8().constData(), attributes, isPublic, isAbstr, methods);

    //classWidget->setStyleSheet("border: 1px solid black;");
    if (editPos == -1)
    {
        classes->push_back(cla);
        int index = classes->size() - 1;

        ClassWidget *classWidget = new ClassWidget(&classes->at(index));
        classWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(classWidget, &QWidget::customContextMenuRequested,
            [this, index](const QPoint &pos) {
                classToExport = index;
                this->showContextMenu(pos);
            });

        ui->sw_classes->addWidget(classWidget);
    }
    else
    {
        classes->at(editPos) = cla;

        ((ClassWidget *) ui->sw_classes->itemAt(editPos)->widget())->display(&classes->at(editPos));
    }
}


void MainWindow::showContextMenu(const QPoint &pos){
    QMenu contextMenu("Actions", this);

    QAction action1("Export...", ui->sw_classes);
    connect(&action1, SIGNAL(triggered()), this, SLOT(handleExportClick()));
    contextMenu.addAction(&action1);

    QAction action2("Edit...", ui->sw_classes);
    connect(&action2, SIGNAL(triggered()), this, SLOT(handleEditClass()));
    contextMenu.addAction(&action2);

    contextMenu.exec(mapToGlobal(pos));
}
