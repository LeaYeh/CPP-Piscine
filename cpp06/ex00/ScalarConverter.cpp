#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _input("")
{
    // std::cout << "Default constructor called: ScalarConverter\n";
}

ScalarConverter::ScalarConverter(const std::string &input) : _input(input)
{
    // std::cout << "Type constructor called: ScalarConverter(" << input << ")\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    // std::cout << "Copy constructor called: ScalarConverter\n";
    this->_input = other._input;
}

ScalarConverter::~ScalarConverter()
{
    // std::cout << "Destructor called: ScalarConverter\n";
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    // std::cout << "Copy operator & called: ScalarConverter\n";
    this->_input = other._input;
    return *this;
}

void ScalarConverter::run(void) const
{
    ADataType *tmp;

    for (int type_idx = 0; type_idx < _MAX_TYPE_NUM; type_idx++)
    {
        if (type_idx == CHAR)
            tmp = new CharType(this->_input);
        else if (type_idx == INT)
            tmp = new IntType(this->_input);
        else if (type_idx == FLOAT)
            tmp = new FloatType(this->_input);
        else if (type_idx == DOUBLE)
            tmp = new DoubleType(this->_input);
        tmp->print();
        delete tmp;
    }
}
