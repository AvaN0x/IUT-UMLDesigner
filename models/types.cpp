#include "models/types.h"

Types *Types::types_ = nullptr;

Types::Types()
{
    typesList_ = (QStringList() << "integer"
                                << "float"
                                << "double"
                                << "boolean"
                                << "long"
                                << "short"
                                << "character");
}

Types *Types::getInstance()
{
    if (types_ == nullptr)
    {
        types_ = new Types();
    }
    return types_;
}

QStringList *Types::getTypes()
{
    return &typesList_;
}
