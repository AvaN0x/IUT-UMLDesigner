#include <iostream>
#include <list>
#include <memory>

#include "mainwindow.h"

#include <QApplication>

#include "models/List.hpp"
#include "models/Class.hpp"
#include "models/Attribute.hpp"
#include "models/Argument.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    iut_cpp::List<iut_cpp::Attribute> attributes;
    attributes.push_last(iut_cpp::Attribute("x", "int", "public", false, "1"));
    attributes.push_last(iut_cpp::Attribute("y", "int", "public", false, "2"));
    attributes.push_last(iut_cpp::Attribute("z", "int", "internal", false));
    attributes.push_last(iut_cpp::Attribute("a", "int", "private", false, "4"));
    attributes.push_last(iut_cpp::Attribute("b", "int", "private", false));
    // attributes.pop_back();

    iut_cpp::Class c1("TestClass", attributes, true, true);

    std::cout << c1.toJava() << std::endl;
    std::cout << iut_cpp::Argument("arg", "int").toJava() << std::endl;
    std::cout << iut_cpp::Argument("arg", "int", "4").toJava() << std::endl;

    return a.exec();
}
