#ifndef PARTICLE_H
#define PARTICLE_H

namespace particleSDL
{
	struct Particle
	{
		double mX;
		double mY;

		double mSpeed;
		double mDirection;


		Particle();
		virtual ~Particle();

		void update(int interval);
	private:
		void init();
	};
}

#endif