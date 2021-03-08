#include <iostream>

#include "mainwindow.h"

#include <QApplication>

#include "List.hpp"
#include "Class.hpp"
#include "Attribute.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    iut_cpp::List<iut_cpp::Attribute> qAttributes;
    qAttributes.push_last(iut_cpp::Attribute("x", "int", false, false, "1"));
    qAttributes.push_last(iut_cpp::Attribute("y", "int", false, false, "2"));
    qAttributes.push_last(iut_cpp::Attribute("z", "int", false, false));
    qAttributes.push_last(iut_cpp::Attribute("a", "int", false, false, "4"));
    qAttributes.push_last(iut_cpp::Attribute("b", "int", false, false));
    // qAttributes.pop_back();

    iut_cpp::Class c1("TestClass", qAttributes, true, true);
    std::cout << c1.toJava() << std::endl;

    return a.exec();
}
