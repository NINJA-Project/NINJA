/**
* @file		Vector3D.h
* @breif	3�����x�N�g���N���X�w�b�_
* @author	shibata
*/

#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D
{
public:
	float x;
	float y;
	float z;

public:
	Vector3D();
	Vector3D(float x_, float y_, float z_);
	~Vector3D();

	// ������Z�q
	Vector3D& operator  = (const Vector3D& vec2D_);

	// ����������Z�q
	Vector3D& operator += (const Vector3D& vec2D_);
	Vector3D& operator -= (const Vector3D& vec2D_);
	Vector3D& operator *= (const Vector3D& vec2D_);
	Vector3D& operator *= (float lhs_);
	Vector3D& operator /= (const Vector3D& vec2D_);
	Vector3D& operator /= (float lhs_);

	// �O�u�C���N�������g
	Vector3D& operator ++ ();
	// ��u�C���N�������g
	Vector3D& operator ++ (int);

	// �O�u�f�N�������g
	Vector3D& operator -- ();
	// ��u�f�N�������g
	Vector3D& operator -- (int);

};

// Vector3D���m��2�����Z�q
Vector3D operator + (const Vector3D& lhs_, const Vector3D& rhs_);
Vector3D operator - (const Vector3D& lhs_, const Vector3D& rhs_);
Vector3D operator * (const Vector3D& lhs_, const Vector3D& rhs_);
Vector3D operator / (const Vector3D& lhs_, const Vector3D& rhs_);

// Vector3D*float��2�����Z�q
Vector3D operator * (const Vector3D& lhs_, float rhs_);
Vector3D operator * (float lhs_, const Vector3D& rhs_);
Vector3D operator / (const Vector3D& lhs_, float rhs_);
Vector3D operator / (float lhs_, const Vector3D& rhs_);

// ��r���Z�q
bool operator < (const Vector3D lhs_, const Vector3D rhs_);
bool operator > (const Vector3D lhs_, const Vector3D rhs_);
bool operator <= (const Vector3D lhs_, const Vector3D rhs_);
bool operator >= (const Vector3D lhs_, const Vector3D rhs_);
bool operator == (const Vector3D lhs_, const Vector3D rhs_);
bool operator != (const Vector3D lhs_, const Vector3D rhs_);


#endif // !VECTOR3D_H