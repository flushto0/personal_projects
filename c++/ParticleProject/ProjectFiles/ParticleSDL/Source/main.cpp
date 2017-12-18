#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
#include "Swarm.h"

#include <ctime>
#include <stdlib.h>
#include <time.h>
#include "main.h"

using namespace particleSDL;

int main(int argc, char *args[])
{
	srand(time(NULL));

	Screen screen;
	Swarm swarm;

	if (!screen.init()) 
	{
		std::cout << "error initializing screen." << std::endl;
	}

	while (true)
	{
		int elapsed = SDL_GetTicks();

		screen.boxBlur();

		swarm.update(elapsed);
		const Particle * const pParticles = swarm.getParticles();
		
		unsigned char red = (unsigned char)(abs((1 + sin(elapsed * 0.0001)) * 128));
		unsigned char green = (unsigned char)(abs(sin(1 + (elapsed * 0.0003))) * 128);
		unsigned char blue = (unsigned char)(abs(sin(1 + (elapsed * 0.0002))) * 128);

		for (int i = 0; i < swarm.NPARTICLES; i++)
		{
			Particle particle = pParticles[i];

			int x = (particle.mX + 1) * Screen::WIDTH / 2;
			int y = (particle.mY * Screen::WIDTH / 2) + Screen::HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}
		/*
		int elapsed = SDL_GetTicks();
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0001) * 128));
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
		 
		std::cout << std::hex << "r: " << (int)red << std::endl;
		std::cout << std::hex << "g: " << (int)green << std::endl;
		std::cout << std::hex << "b: " << (int)blue << std::endl;
		
		screen.drawRect(0, 0, Screen::WIDTH, Screen::HEIGHT, red, green, blue);
		*/


		screen.update();

		if (!screen.processEvents())
		{
			break;
		}	
	}

	screen.close();

	return 0;
}