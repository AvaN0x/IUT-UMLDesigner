#include <algorithm>
#include <fstream>
#include <iostream>

#include "Base.hpp"
#include "Class.hpp"

bool createAndWriteFile(std::string const &fullPath, iut_cpp::Wrapper const &wrapper)
{
    std::ofstream file;
    file.open(fullPath);
    if (!file)
    {
        std::cerr << "Error: could not open file at path : " << fullPath << std::endl;
        return false;
    }

    file << wrapper;
    std::cout << "Class created at path : " << fullPath << std::endl;
    file.close();

    return true;
}

bool createClass(std::string const &path, iut_cpp::Class const &c, std::string const &language)
{
    if (language == "java")
        return createAndWriteFile(path + ".java", c.toJava());

    std::cerr << "Error: Language not found : " << language << std::endl;
    return false;
}

std::string remSpaces(std::string s)
{
    // inspired by https://stackoverflow.com/a/20326454/12183781
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

    return s;
}

std::string toUpper(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}