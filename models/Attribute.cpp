#include <cstdlib>
#include <ostream>
#include <iostream>

#include "Attribute.hpp"

namespace iut_cpp
{
    Attribute::Attribute() : _javaWrapper(nullptr),
                             _name(""),
                             _type(""),
                             _status(""),
                             _isStatic(false),
                             _defaultValue("")
    {
        //constructor
        _javaWrapper = new AttributeJavaWrapper(this);
    }

    Attribute::Attribute(std::string const &name, std::string const &type, std::string status, bool isStatic) : _javaWrapper(nullptr),
                                                                                                                _name(name),
                                                                                                                _type(type),
                                                                                                                _status(status),
                                                                                                                _isStatic(isStatic),
                                                                                                                _defaultValue("")
    {
        //constructor
        _javaWrapper = new AttributeJavaWrapper(this);
    }

    Attribute::Attribute(std::string const &name, std::string const &type, std::string status, bool isStatic, std::string defaultValue) : _javaWrapper(nullptr),
                                                                                                                                          _name(name),
                                                                                                                                          _type(type),
                                                                                                                                          _status(status),
                                                                                                                                          _isStatic(isStatic),
                                                                                                                                          _defaultValue(defaultValue)
    {
        //constructor
        _javaWrapper = new AttributeJavaWrapper(this);
    }

    Attribute::Attribute(Attribute const &a) : _javaWrapper(nullptr),
                                               _name(a._name),
                                               _type(a._type),
                                               _status(a._status),
                                               _isStatic(a._isStatic),
                                               _defaultValue(a._defaultValue)
    {
        //constructor
        _javaWrapper = new AttributeJavaWrapper(this);
    }

    Attribute::~Attribute()
    {
        delete _javaWrapper;
    }

    Attribute &Attribute::operator=(Attribute const &a)
    {
        delete _javaWrapper;
        _javaWrapper = new AttributeJavaWrapper(this);
        _name = a._name;
        _type = a._type;
        _status = a._status;
        _isStatic = a._isStatic;
        _defaultValue = a._defaultValue;

        return *this;
    }

    AttributeJavaWrapper::AttributeJavaWrapper(Attribute *a) : _attribute(a)
    {
    }

    void AttributeJavaWrapper::print(std::ostream &stream) const
    {
        stream << '\t';

        if (_attribute->_status.compare("internal") == 0)
            stream << "protected";
        else
            stream << _attribute->_status;

        stream << ' ';

        if (_attribute->_isStatic)
            stream << "static ";

        // std::cout << _attribute->_name.size();

        stream << _attribute->_type << ' ' << _attribute->_name;

        if (!_attribute->_defaultValue.empty())
            stream << " = " << _attribute->_defaultValue;
        stream << ';' << std::endl;
    }

}