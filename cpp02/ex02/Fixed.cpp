#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << Fixed::_FRACT_BITS)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    this->_value = roundf(value * (1 << Fixed::_FRACT_BITS));
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



std::ostream &operator<<(std::ostream &os, const Fixed &num)
{
    os << num.toFloat();
    return os;
}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
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
