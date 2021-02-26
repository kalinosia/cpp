#pragma once
#include "Particle.h"

namespace domi {

class Swarm
{
public:
	const static int NPARTICLES = 5000; //how many
private:
	Particle *m_pParticles;
	int lastTime;
public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);
	const Particle* const  getParticles() {return m_pParticles;};
};
}//namespace

