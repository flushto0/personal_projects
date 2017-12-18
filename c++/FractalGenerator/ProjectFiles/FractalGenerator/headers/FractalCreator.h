#pragma once
#include <string>
#include <vector>
#include "Zoom.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "RGB.h"

class FractalCreator
{
private:
	int width{ 0 };
	int height{ 0 };
	Bitmap bitmap;
	ZoomList zoomlist;
	unique_ptr<int[]> histogram;
	unique_ptr<int[]> fractal;
	
	vector<int> ranges;
	vector<RGB> colors;
	vector<int> rangetotals;
	bool gotFirstRange{ false };

public:
	int getRange(int iterations) const;

	void run(string filename);
	void addZoom(const Zoom &zoom);
	void addRange(double rangeEnd, const RGB& rgb);
	FractalCreator(int width, int height);
	~FractalCreator();

private:
	
	void calculateIterations();
	void drawFractal();
	void writeBitmap(std::string filename);
	void calculateRangeTotals();

};

