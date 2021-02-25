#include <iostream>
#include <SDL.h>


// You shouldn't really use this statement, but it's fine for small programs
using namespace std;

// You must include the command line parameters for your main function to be recognized by SDL
int main(int argc, char** args) {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	// Initialize SDL. SDL_Init will return -1 if it fails.
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL init failed." << endl;
		// End the program
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 
		SDL_WINDOW_SHOWN);

	if (window == NULL) {
		SDL_Quit();
		return 2;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888,
		SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (renderer == NULL) {
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}
	if (texture == NULL) {
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 4;
	}

	Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // check if memory, if not null....

	memset(buffer, 0 , SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));//second = color = 25 or 0x66 or 0xFF

	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		buffer[i] = 0x00FF00FF; //R G B Opacity
	}
	//buffer[3000] = 0xFFFAAA;


	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	bool quit = false;

	SDL_Event event;

	while (!quit) {
		//Update
		//Draw
		// Checking

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	delete [] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	// Quit SDL
	SDL_Quit();

	// End the program
	return 0;
}