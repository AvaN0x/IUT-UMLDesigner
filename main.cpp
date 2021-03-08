#include <iostream>

#include "mainwindow.h"

#include <QApplication>

#include "Queue.hpp"
#include "Class.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    iut_cpp::Queue<std::string> qAttributes;
    qAttributes.push("attribute_1");
    qAttributes.push("attribute_2");
    qAttributes.push("attribute_3");
    qAttributes.push("attribute_5");
    qAttributes.push("attribute_9");
    // qAttributes.pop(); // FIXME segmentation fault

    iut_cpp::Class c1("ClassName", qAttributes, true, true);
    std::cout << c1 << std::endl;

    return a.exec();
}
