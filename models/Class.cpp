#include <cstdlib>
#include <ostream>

#include "List.hpp"
#include "Class.hpp"
#include "Attribute.hpp"
#include "Method.hpp"

namespace iut_cpp
{
    Class::Class(Class const &c) : _javaWrapper(nullptr),
                                   _name(c._name),
                                   _templates(c._templates),
                                   _attributes(c._attributes),
                                   _isPublic(c._isPublic),
                                   _isAbstract(c._isAbstract),
                                   _methods(c._methods)
    {
        //constructor
        _javaWrapper = new ClassJavaWrapper(this);
    }

    Class::Class(std::string const &name, std::string const &templates, iut_cpp::List<iut_cpp::Attribute> const &attributes, bool isPublic, bool isAbstract, iut_cpp::List<iut_cpp::Method> methods) : _javaWrapper(nullptr),
                                                                                                                                                                                                       _name(name),
                                                                                                                                                                                                       _templates(templates),
                                                                                                                                                                                                       _attributes(attributes),
                                                                                                                                                                                                       _isPublic(isPublic),
                                                                                                                                                                                                       _isAbstract(isAbstract),
                                                                                                                                                                                                       _methods(methods)
    {
        //constructor
        _javaWrapper = new ClassJavaWrapper(this);
    }

    Class::~Class()
    {
        delete _javaWrapper;
    }

    Class &Class::operator=(Class const &c)
    {
        delete _javaWrapper;
        _javaWrapper = new ClassJavaWrapper(this);
        _name = c._name;
        _templates = c._templates;
        _attributes = c._attributes;
        _isPublic = c._isPublic;
        _isAbstract = c._isAbstract;
        _methods = c._methods;

        return *this;
    }

    void Class::addAttribute(iut_cpp::Attribute attribute)
    {
        _attributes.push_last(attribute);
    }

    ClassJavaWrapper::ClassJavaWrapper(Class *c) : _class(c)
    {
    }

    void ClassJavaWrapper::print(std::ostream &stream) const
    {
        stream << (_class->_isPublic ? "public" : "private")
               << ' ';
        if (_class->_isAbstract)
            stream << "abstract ";
        stream << "class " << _class->_name;

        if (!_class->_templates.empty())
            stream << '<' << _class->_templates << '>';

        stream << " {" << std::endl;

        for (auto it = _class->_attributes.begin(); it != _class->_attributes.end(); ++it)
            stream << it->toJava();

        stream << std::endl;

        for (auto it = _class->_methods.begin(); it != _class->_methods.end(); ++it)
            stream << it->toJava() << std::endl;

        stream << '}' << std::endl;
    }
}