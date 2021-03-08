#include <iostream>

#include "mainwindow.h"

#include <QApplication>

#include "Queue.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    iut_cpp::Queue<int> tqueue;
    tqueue.push(1);
    tqueue.push(2);
    tqueue.push(3);
    tqueue.push(5);
    tqueue.push(9);
    tqueue.pop();
    std::cout << tqueue << std::endl;

    return a.exec();
}
