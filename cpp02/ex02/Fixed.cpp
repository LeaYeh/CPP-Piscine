#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int value) : _value(value << Fixed::_FRACT_BITS) {}

Fixed::Fixed(const float value)
{
    this->_value = roundf(value * (1 << Fixed::_FRACT_BITS));
}

Fixed::Fixed(const Fixed &other)
{
    this->_value = other.getRawBits();
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->_value > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->_value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_value != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void)
{
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;

    this->_value++;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &num)
{
    os << num.toFloat();
    return os;
}

int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

int Fixed::toInt(void) const
{
    return this->_value >> Fixed::_FRACT_BITS;
}

float Fixed::toFloat(void) const
{
    return (float)((float)(this->_value) / (float)(1 << Fixed::_FRACT_BITS));
}
