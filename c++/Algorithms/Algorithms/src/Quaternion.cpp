#include <cmath>
#include "Quaternion.h"

Quaternion::Quaternion()
{
}

Quaternion::Quaternion(float w, float x, float y, float z)
	: w(w), x(x), y(y), z(z)
{

}
Quaternion::Quaternion(const Vector3 &axis, float angle)
{
	w = cos(angle / 2);
	x = axis.x * sin(angle / 2);
	y = axis.y * sin(angle / 2);
	z = axis.z * sin(angle / 2);
}
Quaternion::Quaternion(const Vector3 &vector)
{
	w = 0.0f;
	x = vector.x;
	y = vector.y;
	z = vector.z;
}

Quaternion::~Quaternion() //default init of components are all 0
{

}

inline void Quaternion::Normalize()
{
	float length = Length();
	w = w / length;
	x = x / length;
	y = y / length;
	z = z / length;
}

inline float Quaternion::Length()
{
	return sqrt(w*w + x*x + y*y + z*z);
}

inline float Quaternion::LengthSquared()
{
	return w*w + x*x + y*y + z*z;
}

inline float Quaternion::Dot(Quaternion &q)
{

	return w*w + x*x + y*y + z*z;
}

Quaternion operator*(const Quaternion &left, const Quaternion &right)
{
	//take the cross product of xyz, while adjusting for w
	return Quaternion(
		left.w * right.w - left.x * right.x - left.y * right.y - left.z * right.z,
		left.y * right.z - left.z * right.y + left.w * right.x + left.x * right.w,
		left.z * right.x - left.x * right.z + left.w * right.x + left.x * right.w,
		left.x * right.y - left.y * right.x + left.w * right.z + left.z * right.w);
}