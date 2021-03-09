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