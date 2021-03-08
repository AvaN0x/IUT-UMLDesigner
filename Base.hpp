#ifndef DEF_IUT_CPP_BASE_HPP
#define DEF_IUT_CPP_BASE_HPP

#include <ostream>

namespace iut_cpp
{
    class Wrapper;

    class Base
    {
    public:
        virtual const Wrapper &toJava() const = 0;
    };

    class Wrapper
    {
        friend std::ostream &operator<<(std::ostream &stream, Wrapper const &w);

    protected:
        virtual void print(std::ostream &stream) const = 0;
    };

    std::ostream &operator<<(std::ostream &stream, Wrapper const &w);
}

#endif