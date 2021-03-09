#ifndef TYPES_H
#define TYPES_H

#include <QStringList>

class Types {
protected:
    static Types* types_;
    QStringList typesList_;
    Types();
    Types(const QStringList list): typesList_(list){}
public:
    Types(Types &other) = delete;
    void operator=(const Types &) = delete;
    static Types* getInstance();
    QStringList *getTypes();
};

#endif // TYPES_H
