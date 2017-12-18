#pragma once

#include "Vector3.h"

class Quaternion
{
public:
	float w = 0,
		  x = 0, 
		  y = 0,
		  z = 0;

	Quaternion();
	Quaternion(float w, float x, float y, float z);
	Quaternion(const Vector3 &axis, float angle);
	explicit Quaternion(const Vector3 &vector);

	virtual ~Quaternion();
	
	inline void Normalize();
	inline float Length();
	inline float LengthSquared();
	inline float Dot(Quaternion &q);

};

Quaternion operator*(const Quaternion &left, const Quaternion &right);