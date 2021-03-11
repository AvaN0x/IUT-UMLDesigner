#ifndef DEF_IUT_CPP_METHOD_HPP
#define DEF_IUT_CPP_METHOD_HPP

#include <cstdlib>
#include <ostream>
#include <memory>

#include "Base.hpp"
#include "List.hpp"
#include "Argument.hpp"

namespace iut_cpp
{
    class Method;

    class MethodJavaWrapper : public Wrapper
    {
        friend Method;

    protected:
        Method *_method;
        virtual void print(std::ostream &stream) const override;

        MethodJavaWrapper(Method *c);

        virtual ~MethodJavaWrapper() {}
    };

    /**
     * @brief List Method.
     */
    class Method : public Base
    {
        friend MethodJavaWrapper;

    private:
        MethodJavaWrapper *_javaWrapper;
        std::string _name;
        std::string _returnType;
        std::string _status;
        bool _isStatic;
        iut_cpp::List<iut_cpp::Argument> _arguments;

    public:
        /**
         * @brief  Constructor
         */
        Method();

        Method(Method const &m);

        Method(std::string const &name, std::string returnType, std::string status, bool isStatic, iut_cpp::List<iut_cpp::Argument> const &arguments);

        virtual ~Method();

        virtual const Wrapper &toJava() const override
        {
            return *_javaWrapper;
        }

        virtual Method &operator=(Method const &m);
    };

} // namespace iut_cpp

#endif
