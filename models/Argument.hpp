#ifndef DEF_IUT_CPP_ARGUMENT_HPP
#define DEF_IUT_CPP_ARGUMENT_HPP

#include <cstdlib>
#include <ostream>

#include "Attribute.hpp"

namespace iut_cpp
{
    class Argument;

    class ArgumentJavaWrapper : public AttributeJavaWrapper
    {
        friend Argument;

    public:
        virtual void print(std::ostream &stream) const override;

        ArgumentJavaWrapper(Argument *a);
    };

    /**
     * @brief Attribute.
     */
    class Argument : public Attribute
    {
        friend ArgumentJavaWrapper;

    private:
        ArgumentJavaWrapper *_javaWrapper;

    public:
        /**
         * @brief  Constructor
         */
        Argument();

        Argument(Argument const &a);

        /**
         * @brief  Constructor
         */
        Argument(std::string const &name, std::string const &type);
        /**
         * @brief  Constructor
         */
        Argument(std::string const &name, std::string const &type, std::string defaultValue);

        virtual const Wrapper &toJava() const override
        {
            // needed in this case, because it would call Attribute print instead
            return *_javaWrapper;
        }

        virtual Argument &operator=(Argument const &a);
    };

} // namespace iut_cpp

#endif
