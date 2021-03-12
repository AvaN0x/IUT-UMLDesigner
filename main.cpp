#include <iostream>
#include <list>
#include <memory>
#include <fstream>

#include "mainwindow.h"

#include <QApplication>

#include "models/Base.hpp"
#include "models/List.hpp"
#include "models/Class.hpp"
#include "models/Attribute.hpp"
#include "models/Method.hpp"
#include "models/Argument.hpp"

bool createAndWriteFile(std::string const &fullPath, iut_cpp::Wrapper const &wrapper)
{
    std::ofstream file;
    file.open(fullPath);
    if (!file)
    {
        std::cerr << "Error: could not open file at path : " << fullPath << std::endl;
        return false;
    }

    file << wrapper;
    std::cout << "Class created at path : " << fullPath << std::endl;
    file.close();

    return true;
}

bool createClass(std::string const &path, iut_cpp::Class const &c, std::string const &language)
{
    if (language == "java")
        return createAndWriteFile(path + c._name + ".java", c.toJava());

    std::cerr << "Error: Language not found : " << language << std::endl;
    return false;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    iut_cpp::List<iut_cpp::Attribute> attributes;
    attributes.push_last(iut_cpp::Attribute("x", "integer", "public", false, false, "1"));
    attributes.push_last(iut_cpp::Attribute("y", "integer", "public", false, false, "2"));
    attributes.push_last(iut_cpp::Attribute("z", "integer", "internal", false));
    attributes.push_last(iut_cpp::Attribute("a", "character", "private", false, true, "4"));
    attributes.push_last(iut_cpp::Attribute("b", "float", "private", false));

    iut_cpp::List<iut_cpp::Argument> arguments1;
    arguments1.push_last(iut_cpp::Argument("x", "integer", false));
    arguments1.push_last(iut_cpp::Argument("y", "integer", false));

    iut_cpp::List<iut_cpp::Argument> arguments2;
    arguments2.push_last(iut_cpp::Argument("x", "integer", true));
    arguments2.push_last(iut_cpp::Argument("y", "integer", true));
    arguments2.push_last(iut_cpp::Argument("z", "integer", true));

    iut_cpp::List<iut_cpp::Method> methods;
    methods.push_last(iut_cpp::Method("somme", "integer", "public", false, arguments1));
    methods.push_last(iut_cpp::Method("hypothenuse", "double", "private", true, arguments2));

    iut_cpp::Class c1("TestClass", attributes, true, true, methods);

    createClass("", c1, "java");

    return a.exec();
}
