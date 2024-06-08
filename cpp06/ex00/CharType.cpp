#include "CharType.hpp"

CharType::CharType() : ADataType()
{
    this->_data_type = "char";
}

CharType::CharType(const std::string &content) : ADataType(content)
{
    this->_data_type = "char";
}

CharType::CharType(const CharType &other) : ADataType(other) {}

CharType &CharType::operator=(const CharType &other)
{
    if (this != &other)
        ADataType::operator=(other);
    return *this;
}

// 'a' -> NORMAL
// [0, 9999] -> NON_DISPLAY
// "aa" -> NON_DISPLAY
// inf -> IMPOSSIBLE
// 0.1f -> '*'
void CharType::_setValidType(void)
{
    if (this->isValidFloat() && !this->isValidInt())
        this->_check_type = SPECIAL;
    else if (this->_content.length() != 1)
        this->_check_type = NON_DISPLAY;
    else if (std::isprint(this->_content[0]) && !std::isdigit(this->_content[0]))
        this->_check_type = NORMAL;
    else if (this->isNaN() || this->isNegativeInfinity() || this->isPositiveInfinity())
        this->_check_type = IMPOSSIBLE;
    else
        this->_check_type = INVALID;
}

bool CharType::_convert(void)
{
    this->_setValidType();
    if (this->_check_type == SPECIAL)
        this->_converted_result = "'*'";
    else if (this->_check_type != NORMAL)
        return (false);
    else
        this->_converted_result = this->_content[0];
    return (true);
}
