#include <cstdlib>
#include <ostream>
#include <iostream>

#include "Attribute.hpp"

namespace iut_cpp
{
    Attribute::Attribute() : _wrapper(nullptr),
                             _name(""),
                             _type(""),
                             _isPublic(false),
                             _isStatic(false),
                             _defaultValue("")
    {
        //constructor
        _wrapper = new AttributeJavaWrapper(this);
    }

    Attribute::Attribute(std::string const &name, std::string const &type, bool isPublic, bool isStatic) : _wrapper(nullptr),
                                                                                                           _name(name),
                                                                                                           _type(type),
                                                                                                           _isPublic(isPublic),
                                                                                                           _isStatic(isStatic),
                                                                                                           _defaultValue("")
    {
        //constructor
        _wrapper = new AttributeJavaWrapper(this);
        // std::cout << _name << std::endl;
    }

    Attribute::Attribute(std::string const &name, std::string const &type, bool isPublic, bool isStatic, std::string defaultValue) : _wrapper(nullptr),
                                                                                                                                     _name(name),
                                                                                                                                     _type(type),
                                                                                                                                     _isPublic(isPublic),
                                                                                                                                     _isStatic(isStatic),
                                                                                                                                     _defaultValue(defaultValue)
    {
        //constructor
        _wrapper = new AttributeJavaWrapper(this);
    }

    Attribute::~Attribute()
    {
        delete _wrapper;
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

        // std::cout << _attribute->_name.size();

        stream << _attribute->_type << ' ' << _attribute->_name;

        if (!_attribute->_defaultValue.empty())
            stream << " = " << _attribute->_defaultValue;
        stream << ';' << std::endl;
    }

}