#pragma once
#include "Particle.h"

namespace domi {

class Swarm
{
public:
	const static int NPARTICLES = 5000;
private:
	Particle *m_pParticles;
public:
	Swarm();
	virtual ~Swarm();

	const Particle* const  getParticles() {return m_pParticles;};
};
}//namespace

