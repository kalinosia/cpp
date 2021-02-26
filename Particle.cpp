#include "Particle.h"
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

namespace domi {

Particle::Particle() :m_x(0), m_y(0) { 
	m_direction = (2 * M_PI * rand()) / RAND_MAX;
	m_speed = (0.0005 * rand()) / RAND_MAX; //find you speed
}
Particle::~Particle() {

}
void Particle::update(int interval) { //################## MOVING STARS :) WAS HERE ):
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed * interval;
	m_y += yspeed * interval;

}
}