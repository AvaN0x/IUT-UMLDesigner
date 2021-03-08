#include <cstdlib>
#include <ostream>

#include "Base.hpp"

namespace iut_cpp
{

    std::ostream &operator<<(std::ostream &stream, Wrapper const &w)
    {
        w.print(stream);
        return stream;
    }
}