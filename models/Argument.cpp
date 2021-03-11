#include <cstdlib>
#include <ostream>
#include <iostream>

#include "Argument.hpp"

namespace iut_cpp
{
    Argument::Argument() : Attribute("",
                                     "",
                                     "",
                                     false,
                                     "")
    {
        //constructor
        _javaWrapper = new ArgumentJavaWrapper(this);
    }

    Argument::Argument(std::string const &name, std::string const &type) : Attribute(name,
                                                                                     type,
                                                                                     "",
                                                                                     false,
                                                                                     "")
    {
        //constructor
        _javaWrapper = new ArgumentJavaWrapper(this);
    }

    Argument::Argument(std::string const &name, std::string const &type, std::string defaultValue) : Attribute(
                                                                                                         name,
                                                                                                         type,
                                                                                                         "",
                                                                                                         false,
                                                                                                         defaultValue)
    {
        //constructor
        _javaWrapper = new ArgumentJavaWrapper(this);
    }

    Argument::Argument(Argument const &a) : Attribute(
                                                a._name,
                                                a._type,
                                                a._status,
                                                a._isStatic,
                                                a._defaultValue)
    {
        //constructor
        _javaWrapper = new ArgumentJavaWrapper(this);
    }

    Argument &Argument::operator=(Argument const &a)
    {
        Attribute::operator=(a);
        _javaWrapper = new ArgumentJavaWrapper(this);

        return *this;
    }

    ArgumentJavaWrapper::ArgumentJavaWrapper(Argument *a) : AttributeJavaWrapper(a)
    {
    }

    void ArgumentJavaWrapper::print(std::ostream &stream) const
    {
        stream << _attribute->_type << ' ' << _attribute->_name;

        if (!_attribute->_defaultValue.empty())
            stream << " = " << _attribute->_defaultValue;
    }

}