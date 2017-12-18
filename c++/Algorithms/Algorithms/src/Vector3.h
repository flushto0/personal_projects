#pragma once
struct Vector3
{
	float x { 0.0f }, 
		  y { 0.0f }, 
		  z { 0.0f };
	inline Vector3() = default;
	inline Vector3(float x, float y, float z = 0.0f) : x(x), y(y), z(z) 
	{ }
	inline ~Vector3() = default;
	//copy, move assign/ctor implicit

	//Takes the dot product of this* vector and the other vector, or "v dot o"
	float Dot(const Vector3& other) const;
	//returns the distance squared (no sqrt operation) between two vectors.
	float Distance(const Vector3& other) const;
	//returns the distance between two vectors.
	float DistanceSquared(const Vector3& other) const;
	//Takes the cross product of this* vector and the other vector, or "v cross o"
	Vector3 Cross(const Vector3& other) const;
};

Vector3 operator+(const Vector3& left, const Vector3& right);
Vector3 operator-(const Vector3& left, const Vector3& right);
bool operator==(const Vector3& left, const Vector3& right);




