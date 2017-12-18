#pragma once

#include <string>
#include <cstdint>
#include <memory>

using namespace std;

class Bitmap
{
private:
	int width{ 0 };
	int height{ 0 };
	unique_ptr<uint8_t[]> pixels{ nullptr };
public:
	Bitmap(int width, int height);
	bool write(string fileName);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
	void clear(uint8_t red, uint8_t green, uint8_t blue);

	virtual ~Bitmap();

};

