#include "FractalCreator.h"
#include <cassert>

FractalCreator::FractalCreator(int width, int height) : width(width), height(height), histogram(new int[Mandelbrot::MAX_ITERATIONS]{}),
fractal(new int[width*height]{}), bitmap(width, height), zoomlist(width, height)
{
	zoomlist.add(Zoom(width / 2, height / 2, 4.0 / width));
}

FractalCreator::~FractalCreator()
{
}

int FractalCreator::getRange(int iterations) const
{
	int range = 0;

	for (int i = 1; i < ranges.size(); i++) {

		range = i;

		if (ranges[i] > iterations) {
			break;
		}

	}

	range--;

	assert(range > -1);
	assert(range < ranges.size());

	return range;
}

void FractalCreator::calculateIterations()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			pair<double, double> coords = zoomlist.doZoom(x, y);

			int iterations = Mandelbrot::getIterations(coords.first, coords.second);

			fractal[y*width + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS) histogram[iterations]++;

		}
	}
}

void FractalCreator::drawFractal()
{
	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		total += histogram[i];
	}

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int iterations = fractal[y*width + x];
			int range = getRange(iterations);
			int currRangeTotal = rangetotals[range];
			int rangeStart = ranges[range];

			RGB &startcolor = colors[range];
			RGB &endcolor = colors[range + 1];
			RGB colordiff = endcolor - startcolor;

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			int totalpixels = 0;

			if (Mandelbrot::MAX_ITERATIONS != iterations)
			{
				for (int i = rangeStart; i <= iterations; i++)
				{
					totalpixels += histogram[i];
				}
				red = (uint8_t)(startcolor .r + colordiff.r * ((double)totalpixels / currRangeTotal));
				green = (uint8_t)(startcolor.g + colordiff.g * ((double)totalpixels / currRangeTotal));
				blue = (uint8_t)(startcolor.b + colordiff.b * ((double)totalpixels / currRangeTotal));
			}

			bitmap.setPixel(x, y, red, green, blue);

		}
	}
}

void FractalCreator::addZoom(const Zoom &zoom)
{
	zoomlist.add(zoom);
}

void FractalCreator::addRange(double rangeEnd, const RGB & rgb)
{
	ranges.push_back(rangeEnd*Mandelbrot::MAX_ITERATIONS);
	colors.push_back(rgb);

	if (gotFirstRange)
	{
		rangetotals.push_back(0);
	}

	gotFirstRange = true;
}

void FractalCreator::writeBitmap(std::string filename)
{
	bitmap.write(filename);
}

void FractalCreator::calculateRangeTotals()
{
	int rangeIndex = 0;

	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		int pixels = histogram[i];

		if (i >= ranges[rangeIndex + 1]) rangeIndex++;

		rangetotals[rangeIndex] += pixels;
	}
}

void FractalCreator::run(string filename)
{
	calculateIterations();
	calculateRangeTotals();
	drawFractal();
	writeBitmap("fractal.bmp");
}
