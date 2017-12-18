#pragma once
#include <vector>
#include <utility>
#include "Zoom.h"

class ZoomList
{
private:
	int width{ 0 };
	int height{ 0 };
	double xcenter{ 0.0 };
	double ycenter{ 0.0 };
	double scale{ 1.0 };
	std::vector<Zoom> zooms;
public:
	ZoomList(int width, int height);
	void add(const Zoom &zoom);
	std::pair<double, double> doZoom(int x, int y);
};

