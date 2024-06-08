#pragma once

#include "ADataType.hpp"

class FloatType : public ADataType
{
public:
    FloatType();
    FloatType(const FloatType &other);
    FloatType(std::string const &type);
    FloatType &operator=(const FloatType &other);
    virtual ~FloatType();

protected:
    virtual void _setValidType(void);
    virtual bool _convert(void);

private:

};
