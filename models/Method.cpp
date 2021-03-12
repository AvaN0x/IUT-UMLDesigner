#include <cstdlib>
#include <ostream>

#include "List.hpp"
#include "Method.hpp"
#include "Argument.hpp"
#include "types.h"
#include "visibility.h"

namespace iut_cpp
{
    Method::Method() : _javaWrapper(nullptr),
                       _name(""),
                       _returnType(""),
                       _status(""),
                       _isStatic(""),
                       _arguments()
    {
        //constructor
        _javaWrapper = new MethodJavaWrapper(this);
    }

    Method::Method(Method const &m) : _javaWrapper(nullptr),
                                      _name(m._name),
                                      _returnType(m._returnType),
                                      _status(m._status),
                                      _isStatic(m._isStatic),
                                      _arguments(m._arguments)
    {
        //constructor
        _javaWrapper = new MethodJavaWrapper(this);
    }

    Method::Method(std::string const &name, std::string returnType, std::string status, bool isStatic, iut_cpp::List<iut_cpp::Argument> const &arguments) : _javaWrapper(nullptr),
                                                                                                                                                            _name(name),
                                                                                                                                                            _returnType(returnType),
                                                                                                                                                            _status(status),
                                                                                                                                                            _isStatic(isStatic),
                                                                                                                                                            _arguments(arguments)
    {
        //constructor
        _javaWrapper = new MethodJavaWrapper(this);
    }

    Method::~Method()
    {
        if (!_javaWrapper)
            delete _javaWrapper;
    }

    Method &Method::operator=(Method const &m)
    {
        if (!_javaWrapper)
            delete _javaWrapper;
        _javaWrapper = new MethodJavaWrapper(this);
        _name = m._name;
        _returnType = m._returnType;
        _status = m._status;
        _isStatic = m._isStatic;
        _arguments = m._arguments;

        return *this;
    }

    MethodJavaWrapper::MethodJavaWrapper(Method *m) : _method(m)
    {
    }

    void MethodJavaWrapper::print(std::ostream &stream) const
    {
        stream << '\t' << Visibility::getInJava(_method->_status) << ' ';

        if (_method->_isStatic)
            stream << "static ";

        stream << Types::getInJava(_method->_returnType) << ' ' << _method->_name << '(';

        bool isFirst(true);
        for (auto it = _method->_arguments.begin(); it != _method->_arguments.end(); ++it)
        {
            if (!isFirst)
                stream << ", ";
            else
                isFirst = false;
            stream << it->toJava();
        }

        stream << ") {" << std::endl;
        stream << "\t\t// TODO: auto generated function" << std::endl;

        stream << "\t}" << std::endl;
    }
}