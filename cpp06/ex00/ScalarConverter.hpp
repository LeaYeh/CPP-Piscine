#pragma once
#include "CharType.hpp"
#include "IntType.hpp"
#include "DoubleType.hpp"
#include "FloatType.hpp"

class ScalarConverter
{
public:
    static void convert(const std::string &input);

protected:
private:
    static const int _MAX_TYPE_NUM = 4;
    std::string _input;

    ScalarConverter();
    ~ScalarConverter(){};
};
