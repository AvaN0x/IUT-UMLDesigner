#ifndef VISIBILITY_H
#define VISIBILITY_H

#include <QStringList>

class Visibility
{
protected:
    static Visibility* visibility_;
    QStringList visibilityList_;
    Visibility();
public:
    Visibility(Visibility &other) = delete;
    void operator=(const Visibility &) = delete;
    static Visibility* getInstance();
    QStringList *getVisibility();
};

#endif // VISIBILITY_H
