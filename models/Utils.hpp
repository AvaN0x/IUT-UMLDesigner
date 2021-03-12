#ifndef DEF_IUT_CPP_UTILS_HPP
#define DEF_IUT_CPP_UTILS_HPP

#include <algorithm>
#include <fstream>
#include <iostream>

#include "Base.hpp"
#include "Class.hpp"

bool createClass(std::string const &path, iut_cpp::Class const &c, std::string const &language);

bool createAndWriteFile(std::string const &fullPath, iut_cpp::Wrapper const &wrapper);

std::string remSpaces(std::string s);

#endif