#include "ZoomList.h"



ZoomList::ZoomList(int width, int height): width(width), height(height)
{
}

void ZoomList::add(const Zoom &zoom)
{
	zooms.push_back(zoom);
	xcenter += (zoom.x - width / 2)*scale;
	ycenter += (zoom.y - height / 2)*scale;

	scale *= zoom.scale;
	
}
std::pair<double, double> ZoomList::doZoom(int x, int y)
{
	double xfractal = (x - width / 2)*scale + xcenter;
	double yfractal = (y - height / 2)*scale + ycenter;


	return std::pair<double, double>(xfractal, yfractal);
}
