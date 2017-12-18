#include "Matrix3.h"

Matrix3::Matrix3()
{
}

Matrix3::~Matrix3()
{
}

Matrix3& Matrix3::MatrixRotation(const Quaternion & quaternion)
{
	//alternative: if processor supports parallel vector operations, we can just multiply 2 4x4 matrices
	float s, sx, sy, sz, wx, wy, wz, xx, xy, xz, yy, yz, zz;

	// if q is normalized, s=2.0f (basis)
	s = 2.0f / (quaternion.w * quaternion.w + quaternion.x * quaternion.x + quaternion.y * quaternion.y + quaternion.z * quaternion.z);

	sx = s * quaternion.x; sy = s * quaternion.y; sz = s * quaternion.z;
	wx = quaternion.w *	quaternion.x; wy = quaternion.w * quaternion.y; wz = quaternion.w * quaternion.z;
	xx = quaternion.x * quaternion.x; xy = quaternion.x * quaternion.y; xz = quaternion.x * quaternion.z;
	yy = quaternion.y * quaternion.y; yz = quaternion.y * quaternion.z; zz = quaternion.z * quaternion.z;

	matrix[0][0] = 1.0f - (yy + zz); matrix[0][1] = xy + wz;		 matrix[0][2] = xz - wy;

	matrix[1][0] = xy - wz;			 matrix[1][1] = 1.0 - (xx + zz); matrix[1][2] = yz + wx;

	matrix[2][0] = xz + wy;			 matrix[2][1] = yz - wx;		 matrix[2][2] = 1.0f - (xx + yy);

	return *this; //returns the same matrix that we are operating on
}

float& Matrix3::operator()(unsigned int row, unsigned int column)
{
	return matrix[column][row]; //column major
}
Vector3 Matrix3::operator*(const Vector3& vector) const
{
	Vector3 result;
	result.x = matrix[0][0] * vector.x + matrix[1][0] * vector.x + matrix[2][0] * vector.x;
	result.y = matrix[0][1] * vector.y + matrix[1][1] * vector.y + matrix[1][2] * vector.y;
	result.z = matrix[2][0] * vector.z + matrix[2][1] * vector.z + matrix[2][2] * vector.z;

	return result;
}
Matrix3 Matrix3::operator*(const Matrix3& other) const
{
	Matrix3 result;
	result.matrix[0][0] = matrix[0][0] * other.matrix[0][0] + matrix[1][0] * other.matrix[0][1] + matrix[2][0] * other.matrix[0][2];
	result.matrix[0][1] = matrix[0][1] * other.matrix[0][0] + matrix[1][1] * other.matrix[0][1] + matrix[2][1] * other.matrix[0][2];
	result.matrix[0][2] = matrix[0][2] * other.matrix[0][0] + matrix[1][2] * other.matrix[0][1] + matrix[2][2] * other.matrix[0][2];

	result.matrix[1][0] = matrix[0][0] * other.matrix[1][0] + matrix[1][0] * other.matrix[1][1] + matrix[2][0] * other.matrix[1][2];
	result.matrix[1][1] = matrix[0][1] * other.matrix[1][0] + matrix[1][1] * other.matrix[1][1] + matrix[2][1] * other.matrix[1][2];
	result.matrix[1][2] = matrix[0][2] * other.matrix[1][0] + matrix[1][2] * other.matrix[1][1] + matrix[2][2] * other.matrix[1][2];

	result.matrix[2][0] = matrix[0][0] * other.matrix[2][0] + matrix[1][0] * other.matrix[2][1] + matrix[2][0] * other.matrix[2][2];
	result.matrix[2][1] = matrix[0][1] * other.matrix[2][0] + matrix[1][1] * other.matrix[2][1] + matrix[2][1] * other.matrix[2][2];	
	result.matrix[2][2] = matrix[0][2] * other.matrix[2][0] + matrix[1][2] * other.matrix[2][1] + matrix[2][2] * other.matrix[2][2];

	return result;

}
Matrix3 Matrix3::operator+(const Matrix3& other) const
{
	Matrix3 result;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			result.matrix[j][i] = matrix[j][i] + other.matrix[j][i];
		}
	}

	return result;
}
