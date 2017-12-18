#include "RGB.h"

RGB::RGB(double r, double g, double b) : r(r), g(g), b(b)
{
}

RGB operator-(const RGB & c1, const RGB & c2)
{
	return RGB(c1.r - c2.r, c1.g - c2.g, c1.b - c2.b);
}
