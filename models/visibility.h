#ifndef VISIBILITY_H
#define VISIBILITY_H

#include <QStringList>

class Visibility
{
protected:
    static Visibility *visibility_;
    QStringList visibilityList_;
    Visibility();

public:
    Visibility(Visibility &other) = delete;
    void operator=(const Visibility &) = delete;
    static Visibility *getInstance();
    QStringList *getVisibility();

    static std::string getInJava(std::string const &visibility);
    static std::string getInUML(std::string const &visibility);
};

#endif // VISIBILITY_H
