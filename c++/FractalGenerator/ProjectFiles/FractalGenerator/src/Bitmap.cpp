#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"


Bitmap::Bitmap(int width, int height) : width{ width }, height{ height }, pixels(new uint8_t[width*height * 3]{})
{
}

bool Bitmap::write(string fileName)
{
	BitmapFileHeader fheader;
	BitmapInfoHeader iheader;

	fheader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapFileHeader) + (width * height * 3);
	fheader.offset = sizeof(BitmapFileHeader) + sizeof(BitmapFileHeader);
	
	iheader.width = width;
	iheader.height = height;
	
	ofstream file;
	
	file.open(fileName, ios::out | ios::binary);

	if (!file) return false;

	file.write((char *)&fheader, sizeof(fheader));
	file.write((char *)&iheader, sizeof(iheader));
	file.write((char *)pixels.get(), width*height*3);

	file.close();
	if (!file) return false;
	return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
	uint8_t *currpixels = pixels.get();

	currpixels += ((y*3)*width) + (x*3);
	currpixels[0] = blue;
	currpixels[1] = green;
	currpixels[2] = red;
}
void Bitmap::clear(uint8_t red, uint8_t green, uint8_t blue)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			setPixel(x, y, red, green, blue);
		}
	}
}


Bitmap::~Bitmap()
{
}
