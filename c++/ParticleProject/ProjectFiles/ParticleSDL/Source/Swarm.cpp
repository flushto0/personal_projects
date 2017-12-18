#include "Swarm.h"
#include "Screen.h"

particleSDL::Swarm::Swarm() : lastTime(0)
{
	mParticles = new Particle[NPARTICLES];

}

particleSDL::Swarm::~Swarm()
{
	delete[] mParticles;
}

void particleSDL::Swarm::update(int elapsed)
{
	int interval = elapsed - lastTime;

	for (int i = 0; i < NPARTICLES; i++)
	{
		mParticles[i].update(interval);
	}

	lastTime = elapsed;
}
