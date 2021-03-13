#ifndef DEF_IUT_CPP_ARGUMENT_HPP
#define DEF_IUT_CPP_ARGUMENT_HPP

#include <cstdlib>
#include <ostream>
#include "Base.hpp"
namespace iut_cpp
{
    class Argument;

    class ArgumentJavaWrapper : public Wrapper
    {
        friend Argument;

    public:
        Argument *_argument;
        virtual void print(std::ostream &stream) const override;

        ArgumentJavaWrapper(Argument *a);
        virtual ~ArgumentJavaWrapper() {}
    };

    /**
     * @brief Argument.
     */
    class Argument : public Base
    {
        friend ArgumentJavaWrapper;

    private:
        ArgumentJavaWrapper *_javaWrapper;

    public:
        std::string _name;
        std::string _type;
        bool _isConst;
        std::string _defaultValue;
        /**
         * @brief  Constructor
         */
        Argument();

        virtual ~Argument();

        /**
         * @brief  Constructor
         */
        Argument(Argument const &a);

        /**
         * @brief  Constructor
         */
        Argument(std::string const &name, std::string const &type, bool isConst);
        /**
         * @brief  Constructor
         */
        Argument(std::string const &name, std::string const &type, bool isConst, std::string defaultValue);

        std::string toString();

        virtual const Wrapper &toJava() const override
        {
            return *_javaWrapper;
        }

        virtual Argument &operator=(Argument const &a);
    };

} // namespace iut_cpp

#endif
