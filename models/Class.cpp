#include <cstdlib>
#include <ostream>

#include "List.hpp"
#include "Class.hpp"
#include "Attribute.hpp"

namespace iut_cpp
{
    Class::Class(std::string name, iut_cpp::List<iut_cpp::Attribute> attributes, bool isPublic, bool isAbstract) : _wrapper(this),
                                                                                                                   _name(name),
                                                                                                                   _attributes(attributes),
                                                                                                                   _isPublic(isPublic),
                                                                                                                   _isAbstract(isAbstract)
    {
        //constructor
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
        stream << "class " << _class->_name << " {" << std::endl;

        for (auto it = _class->_attributes.begin(); it != _class->_attributes.end(); ++it)
        {
            stream << it->toJava();
        }

        stream << std::endl;

        stream << std::endl;
        stream << '}' << std::endl;
    }
}