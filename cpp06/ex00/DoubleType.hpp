#pragma once

#include "ADataType.hpp"

class DoubleType : public ADataType
{
public:
    DoubleType();
    DoubleType(const DoubleType &other);
    DoubleType(std::string const &type);
    DoubleType &operator=(const DoubleType &other);
    virtual ~DoubleType();

protected:
    virtual void _setValidType(void);
    virtual bool _convert(void);

private:

};
