#include "Vector3.h"
#include <cmath>

float Vector3::Dot(const Vector3& other) const
{
	return (x*other.x + y*other.y + z*other.z);
}

float Vector3::Distance(const Vector3& other) const
{
	float lx = x - other.x;
	float ly = y - other.y;
	float lz = z - other.z;

	return sqrtf(lx * lx + ly * ly + lz * lz); //note: sqrtf might not be efficient for 3d graphics
}

float Vector3::DistanceSquared(const Vector3& other) const
{
	float lx = x - other.x;
	float ly = y - other.y;
	float lz = z - other.z;

	return lx * lx + ly * ly + lz * lz;
}

Vector3 Vector3::Cross(const Vector3& other) const
{
	return Vector3( y*other.z - z*other.y, 
				    x*other.z - z*other.x, 
					x*other.y - y*other.x );
}

Vector3 operator+(const Vector3& left, const Vector3& right)
{
	return Vector3(left.x + right.x, left.y + right.y, left.z + right.z);
}

Vector3 operator-(const Vector3& left, const Vector3& right)
{
	return Vector3(left.x - right.x, left.y - right.y, left.z - right.z);
}

bool operator==(const Vector3& left, const Vector3& right)
{
	return (left.x == right.x && left.y == right.y && left.z == right.z);
}
