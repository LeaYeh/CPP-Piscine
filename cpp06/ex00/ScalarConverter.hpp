#pragma once
#include "CharType.hpp"
#include "IntType.hpp"
#include "DoubleType.hpp"
#include "FloatType.hpp"

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter(std::string const &type);
    ScalarConverter &operator=(const ScalarConverter &other);
    virtual ~ScalarConverter() {};

    void run(void) const;

protected:
private:
    static const int _MAX_TYPE_NUM = 4;
    std::string _input;
};
