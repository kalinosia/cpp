#include <iostream>
#include <math.h>
#include <SDL.h>

#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"

// You shouldn't really use this statement, but it's fine for small programs
using namespace std;
using namespace domi;
// You must include the command line parameters for your main function to be recognized by SDL
int main(int argc, char** args) {

	srand(time(NULL));

	Screen screen;
	if (screen.init() == false) {
		cout << "Error initialising SDL." << endl;
	}

	Swarm swarm;

	bool quit = false;

	while (!quit) {
		if (screen.processEvent() == false){
			break;
		}

	
		
		int elapsed=SDL_GetTicks();
		unsigned char green=(unsigned char)((1+sin(elapsed*0.0001))*128); //[was int to check-cout], 1+ to not have -1, 0.001 to slow, 128 to have almost 255
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);//play with speed = 0.0002 ...
		unsigned char blue = (unsigned char)((1 + cos(elapsed * 0.0003)) * 128);//play with cos and sin
	/*
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red,green,blue); //red pink yellow
			}
		}
		*/

		const Particle* const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		//screen.setPixel(400, 300, 255, 0, 0);
		screen.update();
		
	}
	
	screen.close();

	// End the program
	return 0;
}