#include <iomanip>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Point ab = b - a;
    Point bc = c - b;
    Point ca = a - c;
    Point ap = point - a;
    Point bp = point - b;
    Point cp = point - c;
    bool direction_abap = (ab * ap) > 0;
    bool direction_bcbp = (bc * bp) > 0;
    bool direction_cacp = (ca * cp) > 0;

    return (direction_abap && direction_bcbp && direction_cacp) || (!direction_abap && !direction_bcbp && !direction_cacp);
}

void print_grid(Point const a, Point const b, Point const c)
{
    const int MAX_X = 16;
    const int MAX_Y = 10;

    for (int y = -1; y < MAX_Y; y++)
    {
        if (y != -1)
            std::cout << std::hex << y << " ";
        else
            std::cout << "  ";
        for (int x = 0; x < MAX_X; x++)
        {
            if (y == -1)
            {
                std::cout << std::hex << x;
                continue;
            }
            const Point point = Point(Fixed(x), Fixed(y));

            // print 'x' if the point is at one of triangle points
            if (point == a)
                std::cout << 'A';
            else if (point == b)
                std::cout << 'B';
            else if (point == c)
                std::cout << 'C';
            // print 'o' if the point is outside of triangle
            else if (bsp(a, b, c, point))
                std::cout << 'o';
            // // print '.' if the point is inside of triangle
            else
                std::cout << '.';
        }
        std::cout << std::endl;
    }
}
