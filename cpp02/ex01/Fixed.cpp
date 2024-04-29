#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _FRACT_BITS)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    this->_value = int(value) << _FRACT_BITS;
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_value = other.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
        _value = other.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &num)
{
    os << num.toFloat();
    return os;
}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

int Fixed::toInt(void) const
{
    return _value >> _FRACT_BITS;
}

float Fixed::toFloat(void) const
{
    return _value / (1 << _FRACT_BITS);
}
