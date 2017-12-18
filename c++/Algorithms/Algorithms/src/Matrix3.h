#pragma once
#include "Vector3.h"
#include "Quaternion.h"

class Matrix3
{
public:
	//this array is arranged in column-major format:
	// | 0 3 6 |
	// | 1 4 7 |
	// | 2 5 8 |
	float matrix[3][3] = { 0 };


	Matrix3();
	~Matrix3();
	
	Matrix3& MatrixRotation(const Quaternion& quaternion);
	
	float& operator()(unsigned int row, unsigned int column);
	Vector3 operator*(const Vector3& vector) const;
	Matrix3 operator*(const Matrix3& other) const;
	Matrix3 operator+(const Matrix3& other) const;
};

