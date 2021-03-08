#include <cstdlib>
#include <ostream>

#include "Attribute.hpp"

namespace iut_cpp
{
    Attribute::Attribute() : _wrapper(this),
                             _name(""),
                             _type(""),
                             _isPublic(false),
                             _isStatic(false),
                             _defaultValue("")
    {
        //constructor
    }

    Attribute::Attribute(std::string name, std::string type, bool isPublic, bool isStatic) : _wrapper(this),
                                                                                             _name(name),
                                                                                             _type(type),
                                                                                             _isPublic(isPublic),
                                                                                             _isStatic(isStatic),
                                                                                             _defaultValue("")
    {
        //constructor
    }

    Attribute::Attribute(std::string name, std::string type, bool isPublic, bool isStatic, std::string defaultValue) : _wrapper(this),
                                                                                                                       _name(name),
                                                                                                                       _type(type),
                                                                                                                       _isPublic(isPublic),
                                                                                                                       _isStatic(isStatic),
                                                                                                                       _defaultValue(defaultValue)
    {
        //constructor
    }

    AttributeJavaWrapper::AttributeJavaWrapper(Attribute *a) : _attribute(a)
    {
    }

    void AttributeJavaWrapper::print(std::ostream &stream) const
    {
        stream << '\t' << (_attribute->_isPublic ? "public" : "private")
               << ' ';
        if (_attribute->_isStatic)
            stream << "static ";
        stream << _attribute->_type << ' ' << _attribute->_name;
        if (!_attribute->_defaultValue.empty())
            stream << " = " << _attribute->_defaultValue;
        stream << ';' << std::endl;
    }

}