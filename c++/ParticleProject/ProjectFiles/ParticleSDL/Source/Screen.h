#ifndef SCREEN_H
#define SCREEN_H

#include <SDL.h>
#include <iostream>

namespace particleSDL
{
	class Screen
	{
	public:
		static const int WIDTH = 800;
		static const int HEIGHT = 600;

	private:
		Uint32       *m_buffer1;
		Uint32       *m_buffer2;
		SDL_Window   *m_window;
		SDL_Renderer *m_renderer;
		SDL_Texture  *m_texture;
		
	public:
		Screen();
		bool init();
		bool processEvents();
		void update();
		void setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);
		void close();
		void drawRect(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b);
		void boxBlur();
	};

}

#endif