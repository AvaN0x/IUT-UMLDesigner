#include <iostream>
#include <list>
#include <memory>

#include "mainwindow.h"

#include <QApplication>

#include "models/List.hpp"
#include "models/Class.hpp"
#include "models/Attribute.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    std::list<std::shared_ptr<iut_cpp::Attribute>> attributes;
    attributes.push_back(std::make_shared<iut_cpp::Attribute>("x", "int", false, false, "1"));
    attributes.push_back(std::make_shared<iut_cpp::Attribute>("y", "int", false, false, "2"));
    attributes.push_back(std::make_shared<iut_cpp::Attribute>("z", "int", false, false));
    attributes.push_back(std::make_shared<iut_cpp::Attribute>("a", "int", false, false, "4"));
    attributes.push_back(std::make_shared<iut_cpp::Attribute>("b", "int", false, false));
    // attributes.pop_back();

    iut_cpp::Class c1("TestClass", attributes, true, true);

    std::cout << c1.toJava() << std::endl;

    return a.exec();
    // return 0;
}
