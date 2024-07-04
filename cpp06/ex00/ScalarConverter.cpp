#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &input)
{
    ADataType *tmp;

    for (int type_idx = 0; type_idx < _MAX_TYPE_NUM; type_idx++)
    {
        if (type_idx == CHAR)
            tmp = new CharType(input);
        else if (type_idx == INT)
            tmp = new IntType(input);
        else if (type_idx == FLOAT)
            tmp = new FloatType(input);
        else if (type_idx == DOUBLE)
            tmp = new DoubleType(input);
        tmp->print();
        delete tmp;
    }
}
