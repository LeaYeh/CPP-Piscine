#ifndef __FIXED_HPP
#define __FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    ~Fixed();

    Fixed &operator=(const Fixed &other);

    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _value;
    static const int FRACT_BITS = 8;

    
};

#endif // __FIXED_HPP
