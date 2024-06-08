#pragma once

#include "ADataType.hpp"

class IntType : public ADataType
{
public:
    IntType();
    IntType(const IntType &other);
    IntType(std::string const &type);
    IntType &operator=(const IntType &other);
    virtual ~IntType();

protected:
    virtual void _setValidType(void);
    virtual bool _convert(void);

private:

};
