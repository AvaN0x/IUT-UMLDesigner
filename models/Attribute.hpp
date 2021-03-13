#ifndef DEF_IUT_CPP_ATTRIBUTE_HPP
#define DEF_IUT_CPP_ATTRIBUTE_HPP

#include <cstdlib>
#include <ostream>

#include "Base.hpp"

namespace iut_cpp
{
    class Attribute;

    class AttributeJavaWrapper : public Wrapper
    {
        friend Attribute;

    protected:
        Attribute *_attribute;
        virtual void print(std::ostream &stream) const override;

        AttributeJavaWrapper(Attribute *a);

        virtual ~AttributeJavaWrapper() {}
    };

    /**
     * @brief Attribute.
     */
    class Attribute : public Base
    {
        friend AttributeJavaWrapper;

    private:
        AttributeJavaWrapper *_javaWrapper;

    public:
        std::string _name;
        std::string _type;
        std::string _status;
        bool _isStatic;
        std::string _defaultValue;
        bool _isConst;
        /**
         * @brief  Constructor
         */
        Attribute();

        virtual ~Attribute();

        Attribute(Attribute const &a);

        /**
         * @brief  Constructor
         */
        Attribute(std::string const &name, std::string const &type, std::string status, bool isStatic);
        /**
         * @brief  Constructor
         */
        Attribute(std::string const &name, std::string const &type, std::string status, bool isStatic, bool isConst, std::string defaultValue);

        std::string toString();

        virtual const Wrapper &toJava() const override
        {
            return *_javaWrapper;
        }

        virtual Attribute &operator=(Attribute const &a);
    };

} // namespace iut_cpp

#endif
