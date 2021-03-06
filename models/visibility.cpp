#include "visibility.h"

Visibility *Visibility::visibility_ = nullptr;

Visibility::Visibility()
{
    visibilityList_ = (QStringList() << "public"
                                     << "private"
                                     << "internal");
}

Visibility *Visibility::getInstance()
{
    if (visibility_ == nullptr)
    {
        visibility_ = new Visibility();
    }
    return visibility_;
}

QStringList *Visibility::getVisibility()
{
    return &visibilityList_;
}

std::string Visibility::getInJava(std::string const &visibility)
{
    if (visibility == "internal")
        return "protected";

    return visibility;
}

std::string Visibility::getInUML(std::string const &visibility)
{
    if (visibility == "public")
        return "+";
    else if (visibility == "private")
        return "-";
    else if (visibility == "internal")
        return "#";

    return visibility;
}