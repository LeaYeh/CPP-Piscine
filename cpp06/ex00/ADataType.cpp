#include "ADataType.hpp"


ADataType::ADataType(const std::string &content) : _content(content) {}

ADataType::ADataType(const ADataType &other) : _content(other._content) {}

ADataType &ADataType::operator=(const ADataType &other)
{
    if (this != &other)
        this->_content = other._content;
    return *this;
}

bool ADataType::isNegativeInfinity(void) const
{
    char* end;
    double value = std::strtod(this->_content.c_str(), &end);

    return (*end == '\0' && value == -std::numeric_limits<double>::infinity());
}

bool ADataType::isPositiveInfinity(void) const
{
    char* end;
    double value = std::strtod(this->_content.c_str(), &end);

    return (*end == '\0' && value == std::numeric_limits<double>::infinity());
}

bool ADataType::isNaN(void) const
{
    char* end;
    double value = std::strtod(this->_content.c_str(), &end);

    return (*end == '\0' && value != value);
}

bool ADataType::isValidFloat(void) const
{
    std::string tmp;
    char* end;
    double value;

    tmp = this->_content;
    if (!tmp.empty() && tmp.back() == 'f')
        tmp = tmp.substr(0, tmp.length() - 1);
    value = std::strtod(tmp.c_str(), &end);
    return (*end == '\0' && value != HUGE_VAL && value != -HUGE_VAL);;
}

bool ADataType::isValidInt(void) const
{
    char* end;
    double value;

    value = std::strtol(this->_content.c_str(), &end, 10);
    return (*end == '\0' && errno != ERANGE && \
        value >= std::numeric_limits<int>::min() && \
        value <= std::numeric_limits<int>::max());
}

std::string ADataType::_getNonNormalMessage(void)
{
    if (this->_check_type == IMPOSSIBLE)
        return ("impossible");
    else if (this->_check_type == NON_DISPLAY)
        return ("Non displayable");
    return ("Something wrong...");
}

std::string ADataType::_getMinPrecision(std::string &str) const
{
    std::string result = str;

    result.erase(str.find_last_not_of('0') + 1, std::string::npos);
    if (result.back() == '.')
        result += '0';
    return (result);
}

void ADataType::print(void)
{
    std::cout << this->_data_type << ": ";
    if (this->_convert())
        std::cout << this->_converted_result;
    else
        std::cout << this->_getNonNormalMessage();
    std::cout << std::endl;
}
