#include <cstdlib>
#include <ostream>

#include "List.hpp"
#include "Method.hpp"
#include "Argument.hpp"

namespace iut_cpp
{
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
        delete _javaWrapper;
    }

    Method &Method::operator=(Method const &m)
    {
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
        stream << '\t';
        if (_method->_status.compare("internal") == 0)
            stream << "protected";
        else
            stream << _method->_status;

        stream << ' ';

        if (_method->_isStatic)
            stream << "static ";
        stream << _method->_name << '(';

        for (auto it = _method->_arguments.begin(); it != _method->_arguments.end(); ++it)
        {
            stream << it->toJava() << ", ";
        }

        stream << ") {" << std::endl;
        stream << "\t\t// TODO" << std::endl;

        stream << "\t}" << std::endl;
    }
}