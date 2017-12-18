#include <iostream>
#include <iomanip>
#include <cstdint>
#include "Zoom.h"
#include "FractalCreator.h"

int main()
{
	int const WIDTH = 800;
	int const HEIGHT = 600;

	FractalCreator fcreator(WIDTH, HEIGHT);	

	fcreator.addRange(0.0, RGB(0, 0, 0));
	fcreator.addRange(0.3, RGB(255, 0, 0));
	fcreator.addRange(0.5, RGB(255, 125, 0));
	fcreator.addRange(1.0, RGB(255, 255, 255));

	fcreator.addZoom(Zoom(295, HEIGHT - 202, 0.1));
	fcreator.addZoom(Zoom(312, HEIGHT - 304, 0.1));
	fcreator.run("fractal.bmp");
	
	cout << "finished." << endl;
	return 0;
}



//Bitmap bitmap(WIDTH, HEIGHT);

//unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{});
//unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{});
//ZoomList zoomlist(WIDTH, HEIGHT);

//zoomlist.add(Zoom(WIDTH / 2, HEIGHT / 2, 4.0 / WIDTH));
//zoomlist.add(Zoom(295, HEIGHT - 202, 0.1));
//zoomlist.add(Zoom(312, HEIGHT - 304, 0.1));



//bitmap.clear(255, 0, 0);

//for (int y = 0; y < HEIGHT; y++)
//{
//	for (int x = 0; x < WIDTH; x++)
//	{
//		pair<double, double> coords = zoomlist.doZoom(x, y);

//		int iterations = Mandelbrot::getIterations(coords.first, coords.second);

//		fractal[y*WIDTH + x] = iterations;

//		if (iterations != Mandelbrot::MAX_ITERATIONS) histogram[iterations]++;

//	}
//}

//int total = 0;
//for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
//{
//	total += histogram[i];
//}

//for (int y = 0; y < HEIGHT; y++)
//{
//	for (int x = 0; x < WIDTH; x++)
//	{
//		int iterations = fractal[y*WIDTH + x];
//		double hue = 0.0;
//		uint8_t red = 0;
//		uint8_t green = (uint8_t)pow(255, hue);
//		uint8_t blue = 0;

//		if (Mandelbrot::MAX_ITERATIONS != iterations)
//		{
//			for (int i = 0; i <= iterations; i++)
//			{
//				hue += ((double)histogram[i]) / total;
//			}
//			green = (uint8_t)pow(255, hue);
//		}

//		bitmap.setPixel(x, y, red, green, blue);

//	}
//}

//bitmap.write("test.bmp");