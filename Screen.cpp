#include <iostream>
#include "Screen.h"


namespace domi {

Screen::Screen() :
	m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {
	//m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // check if memory, if not null....
}
//-----------------------------------------------------------------------INIT
bool Screen::init() {
	
	// Initialize SDL. SDL_Init will return false if it fails.
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explosion", //SDL_Window* window->m_window because declaration in .h
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_ABGR8888,
		SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}
	if (m_texture == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		SDL_Quit();
		return false;
	}

	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // check if memory, if not null....

	memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32)); //second = color = 25 or 0x66 or 0xFF

	
	return true;
}
//----------------------------------------------------------------------------------UPDATE
void Screen::update() {
	/*
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		m_buffer[i] = 0xFFFF0000; //R G B Opacity NOT NOTHOW HOW? OPACITY BLUE GREEN RED!!!!!
	}
	*/
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}
//------------------------------------------------------------------------------PIXELS
void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	Uint32 color = 0;
	/*dont know why but oposite in my
	* not R G B alpha
	* but alpha r g b ??
	* 
	color += red; 
	color <<= 8; //move 2 places, 8 bits to left (...)
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;
	*/

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		return;
	}

	color += 0xFF;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += green;
	color <<= 8;
	color += red;

	m_buffer[(y * SCREEN_WIDTH) + x] = color;
}

//---------------------------------------------------------------------------EVENT
bool Screen::processEvent() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

//--------------------------------------------------------------------------CLOSE
void Screen::close() {
	delete[] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	// Quit SDL
	SDL_Quit();
}

}//namespace
