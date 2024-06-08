#include "FloatType.hpp"

FloatType::FloatType() : ADataType()
{
    this->_data_type = "float";
}

FloatType::FloatType(const std::string &content) : ADataType(content)
{
    this->_data_type = "float";
}

FloatType::FloatType(const FloatType &other) : ADataType(other) {}

FloatType &FloatType::operator=(const FloatType &other)
{
    if (this != &other)
        ADataType::operator=(other);
    return *this;
}

void FloatType::_setValidType(void)
{
    if (!this->isValidFloat() && !this->isNaN() && \
        !this->isNegativeInfinity() && !this->isPositiveInfinity())
        this->_check_type = IMPOSSIBLE;
    else
        this->_check_type = NORMAL;
}

bool FloatType::_convert(void)
{
    this->_setValidType();
    if (this->_check_type != NORMAL)
        return (false);
    else if (this->isNaN())
        this->_converted_result = "nan";
    else if (this->isNegativeInfinity())
        this->_converted_result = "-inf";
    else if (this->isPositiveInfinity())
        this->_converted_result = "inf";
    else
        this->_converted_result = std::to_string(
            std::strtod(this->_content.c_str(), NULL)
        );
    this->_converted_result = this->_getMinPrecision(this->_converted_result);
    this->_converted_result += "f";
    return (true);
}
