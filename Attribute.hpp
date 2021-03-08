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
    };

    /**
     * @brief Attribute.
     */
    class Attribute : public Base
    {
        friend AttributeJavaWrapper;

    private:
        AttributeJavaWrapper _wrapper;
        std::string _name;
        std::string _type;
        bool _isPublic;
        bool _isStatic; // TODO @OxyT0m add it to the UI
        std::string _defaultValue;

    public:
        /**
         * @brief  Constructor
         */
        Attribute();

        /**
         * @brief  Constructor
         */
        Attribute(std::string name, std::string type, bool isPublic, bool isStatic);
        /**
         * @brief  Constructor
         */
        Attribute(std::string name, std::string type, bool isPublic, bool isStatic, std::string defaultValue);

        virtual const Wrapper &toJava() const override
        {
            return _wrapper;
        }
    };

} // namespace iut_cpp

#endif
