#pragma once

#include "ADataType.hpp"

class CharType : public ADataType
{
public:
    CharType();
    CharType(const CharType &other);
    CharType(std::string const &type);
    CharType &operator=(const CharType &other);
    virtual ~CharType();

protected:
    virtual void _setValidType(void);
    virtual bool _convert(void);

private:

};
