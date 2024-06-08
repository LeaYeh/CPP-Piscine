#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _input("") {}

ScalarConverter::ScalarConverter(const std::string &input) : _input(input) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) : _input(other._input) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
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
