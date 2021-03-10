#include <cstdlib>
#include <ostream>

#include "List.hpp"
#include "Class.hpp"
#include "Attribute.hpp"

namespace iut_cpp
{
    Class::Class(std::string const &name, std::list<std::shared_ptr<iut_cpp::Attribute>> const &attributes, bool isPublic, bool isAbstract) : _wrapper(nullptr),
                                                                                                                                              _name(name),
                                                                                                                                              _attributes(attributes),
                                                                                                                                              _isPublic(isPublic),
                                                                                                                                              _isAbstract(isAbstract)
    {
        //constructor
        _wrapper = new ClassJavaWrapper(this);
    }

    Class::~Class()
    {
        delete _wrapper;
    }

    void Class::addAttribute(std::shared_ptr<iut_cpp::Attribute> attribute)
    {
        _attributes.push_back(attribute);
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
            stream << (*it)->toJava();
        }

        stream << std::endl;

        stream << std::endl;
        stream << '}' << std::endl;
    }
}