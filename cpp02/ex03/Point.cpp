#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()) {}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}

Point::~Point() {}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
    {
        // This one works, but this is an undefined behavior
        // https://en.cppreference.com/w/cpp/language/const_cast
        // const_cast<Fixed&>(_x) = other.getX();
        // const_cast<Fixed&>(_y) = other.getY();
        // Copy operator be called, but the attr. is const!
        // I think delete the copy operator is more safty but the subject ask me to overwrite ...
        // so I decide to overwirte but do nothing in copy operator
    }
    return *this;
}

Point Point::operator-(const Point &other) const
{
    const Fixed x = this->getX() - other.getX();
    const Fixed y = this->getY() - other.getY();

    return Point(x, y);
}

Fixed Point::operator*(const Point &other) const
{
    return this->getX() * other.getY() - this->getY() * other.getX();
}

bool Point::operator==(const Point &other) const
{
    return (this->getX() == other.getX()) && (this->getY() == other.getY());
}

const Fixed &Point::getX(void) const
{
    return this->_x;
}

const Fixed &Point::getY(void) const
{
    return this->_y;
}

std::ostream &operator<<(std::ostream &os, const Point &point)
{
    os << "Point(" << point.getX() << ", " << point.getY() << ")";
    return os;
}
