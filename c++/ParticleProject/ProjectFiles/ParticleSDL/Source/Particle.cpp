#define _USE_MATH_DEFINES

#include "Particle.h"
#include <stdlib.h>
#include <math.h>

namespace particleSDL
{
	Particle::Particle() : mX(0), mY(0)
	{
		init();
	}
	
	Particle::~Particle()
	{

	}
	void Particle::update(int interval)
	{
		mDirection += interval * 0.0004;

		double xspeed = mSpeed * cos(mDirection);
		double yspeed = mSpeed * sin(mDirection);

		mX += xspeed * interval;
		mY += yspeed * interval;

		if (mX < -1 || mX > 1 || mY < -1 || mY > 1)
		{
			init();
		}
	}
	void Particle::init()
	{
		mX = 0;
		mY = 0;

		mDirection = (2 * M_PI * rand()) / RAND_MAX;
		mSpeed = (0.0004 * rand()) / RAND_MAX;
		mSpeed += mSpeed;
	}
}