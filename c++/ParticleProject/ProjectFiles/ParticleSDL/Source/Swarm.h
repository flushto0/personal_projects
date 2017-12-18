#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

namespace particleSDL
{
	class Swarm
	{
	public: 
			const static int NPARTICLES = 6000;
	private:
		Particle* mParticles;
		int lastTime;
	public:
		Swarm();
		virtual ~Swarm();

		void update(int elapsed);

		Particle * getParticles() const { return mParticles; }
	};
}

#endif
