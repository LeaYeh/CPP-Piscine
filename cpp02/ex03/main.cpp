#include "Point.hpp"

int main(void)
{
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(0), Fixed(1));
	Point c(Fixed(1), Fixed(0));
	
	print_grid(a, b, c);

	return (0);
}
