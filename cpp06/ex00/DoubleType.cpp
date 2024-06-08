#include "DoubleType.hpp"

DoubleType::DoubleType() : ADataType()
{
    // std::cout << "Default constructor called: DoubleType\n";
    this->_data_type = "double";
}

DoubleType::DoubleType(const std::string &content) : ADataType(content)
{
    // std::cout << "Type constructor called: DoubleType(" << content << ")\n";
    this->_data_type = "double";
}

DoubleType::DoubleType(const DoubleType &other) : ADataType(other)
{
    // std::cout << "Copy constructor called: DoubleType\n";
}

DoubleType::~DoubleType()
{
    // std::cout << "Destructor called: DoubleType\n";
}

DoubleType &DoubleType::operator=(const DoubleType &other)
{
    // std::cout << "Copy operator & called: DoubleType\n";
    if (this != &other)
        ADataType::operator=(other);
    return *this;
}

void DoubleType::_setValidType(void)
{
    if (!this->isValidFloat() && !this->isNaN() && \
        !this->isNegativeInfinity() && !this->isPositiveInfinity())
        this->_check_type = IMPOSSIBLE;
    else
        this->_check_type = NORMAL;
}

bool DoubleType::_convert(void)
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
    return (true);
}
