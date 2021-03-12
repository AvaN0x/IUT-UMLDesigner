#include <iostream>
#include <list>
#include <memory>
#include <fstream>

// #include "mainwindow.h"

// #include <QApplication>

#include "models/Base.hpp"
#include "models/List.hpp"
#include "models/Class.hpp"
#include "models/Attribute.hpp"
#include "models/Method.hpp"
#include "models/Argument.hpp"

/**
 * @brief  Write a content into a file at a path
 * @param  path: must contain extension at the end of file
 * @param  wrapper: content to write
 * @return bool, success or error
 */
bool writeInFile(std::string const &path, iut_cpp::Wrapper const &wrapper)
{
    std::ofstream file;

    //TODO generate file name with extension
    file.open(path);
    if (!file)
    {
        std::cerr << "Error: could not open file at path : " << path << std::endl;
        return false;
    }

    file << wrapper;
    std::cout << "Class created at path : " << path << std::endl;
    file.close();

    return true;
}

int main(int argc, char *argv[])
{
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    iut_cpp::List<iut_cpp::Attribute> attributes;
    attributes.push_last(iut_cpp::Attribute("x", "int", "public", false, "1"));
    attributes.push_last(iut_cpp::Attribute("y", "int", "public", false, "2"));
    attributes.push_last(iut_cpp::Attribute("z", "int", "internal", false));
    attributes.push_last(iut_cpp::Attribute("a", "int", "private", false, "4"));
    attributes.push_last(iut_cpp::Attribute("b", "int", "private", false));

    iut_cpp::List<iut_cpp::Argument> arguments1;
    arguments1.push_last(iut_cpp::Argument("x", "int"));
    arguments1.push_last(iut_cpp::Argument("y", "int"));

    iut_cpp::List<iut_cpp::Argument> arguments2;
    arguments2.push_last(iut_cpp::Argument("x", "int", "0"));
    arguments2.push_last(iut_cpp::Argument("y", "int", "0"));
    arguments2.push_last(iut_cpp::Argument("z", "int", "0"));

    iut_cpp::List<iut_cpp::Method> methods;
    methods.push_last(iut_cpp::Method("somme", "int", "public", true, arguments1));
    methods.push_last(iut_cpp::Method("hypothenuse", "int", "public", true, arguments2));

    iut_cpp::Class c1("TestClass", attributes, true, true, methods);

    writeInFile("Test.java", c1.toJava());

    // return a.exec();
    return 0;
}
