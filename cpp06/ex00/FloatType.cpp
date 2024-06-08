#include "FloatType.hpp"

FloatType::FloatType() : ADataType()
{
    // std::cout << "Default constructor called: FloatType\n";
    this->_data_type = "float";
}

FloatType::FloatType(const std::string &content) : ADataType(content)
{
    // std::cout << "Type constructor called: FloatType(" << content << ")\n";
    this->_data_type = "float";
}

FloatType::FloatType(const FloatType &other) : ADataType(other)
{
    // std::cout << "Copy constructor called: FloatType\n";
}

FloatType::~FloatType()
{
    // std::cout << "Destructor called: FloatType\n";
}

FloatType &FloatType::operator=(const FloatType &other)
{
    // std::cout << "Copy operator & called: FloatType\n";
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
