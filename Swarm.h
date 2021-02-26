#pragma once
#include "Particle.h"

namespace domi {

class Swarm
{
public:
	const static int NPARTICLES = 1000; //how many
private:
	Particle *m_pParticles;
public:
	Swarm();
	virtual ~Swarm();
	void update();
	const Particle* const  getParticles() {return m_pParticles;};
};
}//namespace

