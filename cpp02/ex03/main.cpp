#include "Point.hpp"

int main(void)
{
	Point a(Fixed(2), Fixed(8));
	Point b(Fixed(8), Fixed(4));
	Point c(Fixed(3), Fixed(1));
	Point p(Fixed(3), Fixed(2));

	print_grid(a, b, c);

	std::cout << p << (bsp(a, b, c, Point(Fixed(3), Fixed(2))) ? ", is inside of the triangle\n" : ", is outside of the triangle\n");

	return (0);
}
