#include "IntType.hpp"

IntType::IntType() : ADataType()
{
    this->_data_type = "int";
}

IntType::IntType(const std::string &content) : ADataType(content)
{
    this->_data_type = "int";
}

IntType::IntType(const IntType &other) : ADataType(other) {}

IntType &IntType::operator=(const IntType &other)
{
    if (this != &other)
        ADataType::operator=(other);
    return *this;
}

void IntType::_setValidType(void)
{
    if (this->isNaN() || !this->isValidFloat())
        this->_check_type = IMPOSSIBLE;
    else
        this->_check_type = NORMAL;
}

bool IntType::_convert(void)
{
    this->_setValidType();
    if (this->_check_type != NORMAL)
        return (false);
    else
        this->_converted_result = std::to_string(
            std::strtol(this->_content.c_str(), NULL, 10)
        );
    return (true);
}
