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

    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    Fixed &operator++(void);
    Fixed operator++(int);

    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _value;
    static const int _FRACT_BITS = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &num);

#endif // __FIXED_HPP