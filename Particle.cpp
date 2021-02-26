#include "Particle.h"
#include <stdlib.h>

namespace domi {

Particle::Particle() { //Particle::Particle():m_x(0),m_y(0) ->from center
	m_x = ((2.0*rand()) / RAND_MAX)-1; //RAND_MAX=32767
	m_y = ((2.0 * rand()) / RAND_MAX) - 1;

	m_xspeed = 0.0025 * (((2.0 * rand()) / RAND_MAX) - 1); //SPEED CHANGE HERE!!!!!!
	m_yspeed = 0.0025 * (((2.0 * rand()) / RAND_MAX) - 1);
	}
Particle::~Particle() {

}
void Particle::update() { //################## MOVING STARS :)
	//-----YOU CAN TRY THIS BUT DELETE DECLARATION IN PARTICLE.CPP & PARTICLE.H in constructor-----
	//const double speed = 0.01; //1.0 diagonaly move...
	//const double xspeed = (0.001* rand()) / RAND_MAX; //2.0 diagonaly move in different speed
	//const double xspeed = 0.01 * (((2.0 * rand()) / RAND_MAX)-1); //3.0 move like swarm 
	//const double yspeed = 0.01 * (((2.0 * rand()) / RAND_MAX) - 1); 

	m_x += m_xspeed;
	m_y += m_yspeed;

	//ALSO TRY DELETE THIS, stars lost in edges, slow moving, 
	//ALSO CHANGE const static int NPARTICLES = 5000; and m_yspeed = 0.01 * (((2.0 * rand()) / RAND_MAX) - 1);.. to better see
	if (m_x < -1.0 || m_x >= 1.0) {
		m_xspeed = -m_xspeed;
	}
	if (m_y < -1.0 || m_y >= 1.0) {
		m_yspeed = -m_yspeed;
	}
}
}