#pragma once
struct RGB
{
	double r;
	double g;
	double b;
	RGB(double r, double g, double b);
	friend RGB operator-(const RGB &c1, const RGB &c2);
};

