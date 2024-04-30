#ifndef __POINT_HPP
#define __POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
    Point();
    Point(const Point &other);
    Point(const Fixed x, const Fixed y);
    ~Point();

    Point &operator=(const Point &other);
    Point operator-(const Point &other) const;
    Fixed operator*(const Point &other) const;
    bool operator==(const Point &other) const;

    const Fixed &getX(void) const;
    const Fixed &getY(void) const;

private:
    const Fixed _x;
    const Fixed _y;
};

std::ostream &operator<<(std::ostream &os, const Point &point);
bool bsp(Point const a, Point const b, Point const c, Point const point);
void print_grid(Point const a, Point const b, Point const c);

#endif // __POINT_HPP
