#pragma once

#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits>

enum ValidResultType
{
    NUL,
    NORMAL,
    NON_DISPLAY,
    IMPOSSIBLE,
    SPECIAL,
    INVALID
};
enum TypeIndex
{
    CHAR = 0,
    INT,
    FLOAT,
    DOUBLE
};

class ADataType
{
public:
    ADataType() {};
    ADataType(const ADataType &other);
    ADataType(std::string const &type);
    ADataType &operator=(const ADataType &other);
    virtual ~ADataType() {};

    bool isNegativeInfinity(void) const;
    bool isPositiveInfinity(void) const;
    bool isNaN(void) const;
    bool isValidFloat(void) const;
    bool isValidInt(void) const;
    virtual void print(void);

protected:
    std::string _data_type;
    std::string _content;
    std::string _converted_result;
    ValidResultType _check_type;
    std::string _getNonNormalMessage(void);
    std::string _getMinPrecision(std::string &str) const;
    virtual void _setValidType(void) = 0;
    virtual bool _convert(void) = 0;

private:
};
