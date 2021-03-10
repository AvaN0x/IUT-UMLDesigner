#ifndef DEF_IUT_CPP_CLASS_HPP
#define DEF_IUT_CPP_CLASS_HPP

#include <cstdlib>
#include <ostream>
#include <list>
#include <memory>

#include "Base.hpp"
#include "List.hpp"
#include "Attribute.hpp"

namespace iut_cpp
{
    class Class;

    class ClassJavaWrapper : public Wrapper
    {
        friend Class;

    protected:
        Class *_class;
        virtual void print(std::ostream &stream) const override;

        ClassJavaWrapper(Class *c);

        virtual ~ClassJavaWrapper() {}
    };

    /**
     * @brief List Class.
     */
    class Class : public Base
    {
        friend ClassJavaWrapper;

    private:
        ClassJavaWrapper *_javaWrapper;
        std::string _name;
        iut_cpp::List<iut_cpp::Attribute> _attributes; //? todo change to attribute class
        bool _isPublic;
        bool _isAbstract;

    public:
        /**
         * @brief  Constructor
         */
        Class(Class const &c);

        Class(std::string const &name, iut_cpp::List<iut_cpp::Attribute> const &attributes, bool isPublic, bool isAbstract);

        virtual ~Class();

        void addAttribute(iut_cpp::Attribute attribute);

        virtual const Wrapper &toJava() const override
        {
            return *_javaWrapper;
        }

        virtual Class &operator=(Class const &c);
    };

} // namespace iut_cpp

#endif
