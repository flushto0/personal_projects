#include "Screen.h"
namespace particleSDL
{
	Screen::Screen() :
		m_window(NULL),
		m_renderer(NULL),
		m_texture(NULL),
		m_buffer1(NULL),
		m_buffer2(NULL)
	{
		
	}

	bool Screen::processEvents()
	{
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return false;
			}
		}
		return true;
	}
	void Screen::update()
	{
		SDL_UpdateTexture(m_texture, NULL, m_buffer1, WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}
	void Screen::setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b)
	{
		if (((y * WIDTH) + x) < 0 || ((y * WIDTH) + x) > (Screen::WIDTH * Screen::HEIGHT) || x < 0 || x > Screen::WIDTH)
		{
			return;
		}

		Uint32 color = 0;

		color += r;
		color <<= 8;
		color += g;
		color <<= 8;
		color += b;
		color <<= 8;
		color += 0xFF;

		m_buffer1[(y * WIDTH) + x] = color;
	}

	bool Screen::init()
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			return false;
		}

		m_window = SDL_CreateWindow
		(
			"Particle Effect",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			WIDTH,
			HEIGHT,
			SDL_WINDOW_SHOWN
		);

		if (!m_window)
		{
			SDL_Quit();
			return false;
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, WIDTH, HEIGHT);

		if (!m_renderer)
		{
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		if (!m_texture)
		{
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		m_buffer1 = new Uint32[WIDTH * HEIGHT];
		m_buffer2 = new Uint32[WIDTH * HEIGHT];

		memset(m_buffer1, 0x00, WIDTH*HEIGHT * sizeof(Uint32));
		memset(m_buffer2, 0x00, WIDTH*HEIGHT * sizeof(Uint32));


		//for (int i = 0; i < WIDTH*HEIGHT; i++)
		//{
		//	m_buffer[i] = 0xDDAA55FF;
		//}

		SDL_UpdateTexture(m_texture, NULL, m_buffer1, WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);

		return true;
	}
	void Screen::close()
	{
		delete[] m_buffer1;
		delete[] m_buffer2;

		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	void Screen::drawRect(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b)
	{
		for (int u = 0; u < width; u++)
		{
			for (int v = 0; v < height; v++)
			{
				setPixel(u, v, r, g, b);
			}
		}
	}

	void Screen::boxBlur()
	{
		Uint32 *temp = m_buffer1;
		m_buffer1 = m_buffer2;
		m_buffer2 = temp;

		for (int y = 0; y < HEIGHT; y++)
		{
			for (int x = 0; x < WIDTH; x++)
			{

				int redTotal = 0;
				int greenTotal = 0;
				int blueTotal = 0;

				for (int row = -1; row <= 1; row++)
				{
					for (int col = -1; col <= 1; col++)
					{
						int curr_x = x + col;
						int curr_y = y + row;

						if (curr_x >= 0 && curr_x < WIDTH && curr_y >= 0 && curr_y < HEIGHT)
						{
							Uint32 color = m_buffer2[(curr_y * WIDTH) + curr_x];

							Uint8 red = color >> 24;
							Uint8 green = color >> 16;
							Uint8 blue = color >> 8;

							redTotal += red;
							greenTotal += green;
							blueTotal += blue;

						}

					}
				}

				Uint8 red = redTotal / 9;
				Uint8 green = greenTotal / 9;
				Uint8 blue = blueTotal / 9;

				setPixel(x, y, red, green, blue);

			}
		}
	}

}