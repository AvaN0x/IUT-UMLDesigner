#ifndef DEF_IUT_CPP_CLASS_HPP
#define DEF_IUT_CPP_CLASS_HPP

#include <cstdlib>
#include <ostream>

#include "Queue.hpp"

namespace iut_cpp
{
    /**
     * @brief Queue Class.
     */
    class Class
    {
    private:
        std::string _name;
        iut_cpp::Queue<std::string> _attributes; //? todo change to attribute class
        bool _isPublic = false;
        bool _isAbstract = false;

    public:
        /**
         * @brief  Constructor
         */
        Class(std::string name, iut_cpp::Queue<std::string> attributes, bool isPublic, bool isAbstract);

        /**
         * @brief  Write the class to the stream
         * @param  stream: stream to write on
         */
        void print(std::ostream &stream) const;
    };

    Class::Class(std::string name, iut_cpp::Queue<std::string> attributes, bool isPublic, bool isAbstract) : _name(name),
                                                                                                             _attributes(attributes),
                                                                                                             _isPublic(isPublic),
                                                                                                             _isAbstract(isAbstract)
    {
        //constructor
    }

    void Class::print(std::ostream &stream) const
    {
        stream << (_isPublic ? "public" : "private")
               << " ";
        if (_isAbstract)
            stream << "abstract ";
        stream << "class " << _name << " {" << std::endl;

        stream << _attributes;

        stream << std::endl;
        stream << "}" << std::endl;
    }

    std::ostream &operator<<(std::ostream &stream, Class const &c)
    {
        c.print(stream);
        return stream;
    }

} // namespace iut_cpp

#endif
