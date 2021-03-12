#include <cstdlib>
#include <ostream>
#include <iostream>

#include "Argument.hpp"
#include "types.h"

namespace iut_cpp
{
    Argument::Argument() : _javaWrapper(nullptr),
                           _name(""),
                           _type(""),
                           _defaultValue("")
    {
        //constructor
        _javaWrapper = new ArgumentJavaWrapper(this);
    }

    Argument::Argument(std::string const &name, std::string const &type) : _javaWrapper(nullptr),
                                                                           _name(name),
                                                                           _type(type),
                                                                           _defaultValue("")
    {
        //constructor
        _javaWrapper = new ArgumentJavaWrapper(this);
    }

    Argument::Argument(std::string const &name, std::string const &type, std::string defaultValue) : _javaWrapper(nullptr),
                                                                                                     _name(name),
                                                                                                     _type(type),
                                                                                                     _defaultValue(defaultValue)
    {
        //constructor
        _javaWrapper = new ArgumentJavaWrapper(this);
    }

    Argument::Argument(Argument const &a) : _javaWrapper(nullptr),
                                            _name(a._name),
                                            _type(a._type),
                                            _defaultValue(a._defaultValue)
    {
        //constructor
        _javaWrapper = new ArgumentJavaWrapper(this);
    }

    Argument::~Argument()
    {
        if (!_javaWrapper)
            delete _javaWrapper;
    }

    Argument &Argument::operator=(Argument const &a)
    {
        if (!_javaWrapper)
            delete _javaWrapper;
        _javaWrapper = new ArgumentJavaWrapper(this);
        _name = a._name;
        _type = a._type;
        _defaultValue = a._defaultValue;

        return *this;
    }

    ArgumentJavaWrapper::ArgumentJavaWrapper(Argument *a) : _argument(a)
    {
    }

    void ArgumentJavaWrapper::print(std::ostream &stream) const
    {
        stream << Types::getInJava(_argument->_type) << ' ' << _argument->_name;
    }

}