/**
 * @file	Vector2D.h
 * @breif	2�����x�N�g���N���X�w�b�_
 * @author	shibata
 */

#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
public:
	float x;
	float y;

public:
	Vector2D();
	Vector2D(float x_, float y_);

	// ������Z�q
	Vector2D& operator  = (const Vector2D& vec2D_);

	// ����������Z�q
	Vector2D& operator += (const Vector2D& vec2D_);
	Vector2D& operator -= (const Vector2D& vec2D_);
	Vector2D& operator *= (const Vector2D& vec2D_);
	Vector2D& operator *= (float lhs_);
	Vector2D& operator /= (const Vector2D& vec2D_);
	Vector2D& operator /= (float lhs_);

	// �O�u�C���N�������g
	Vector2D& operator ++ ();
	// ��u�C���N�������g
	Vector2D& operator ++ (int);

	// �O�u�f�N�������g
	Vector2D& operator -- ();
	// ��u�f�N�������g
	Vector2D& operator -- (int);

};

// Vector2D���m��2�����Z�q
Vector2D operator + (const Vector2D& lhs_, const Vector2D& rhs_);
Vector2D operator - (const Vector2D& lhs_, const Vector2D& rhs_);
Vector2D operator * (const Vector2D& lhs_, const Vector2D& rhs_);
Vector2D operator / (const Vector2D& lhs_, const Vector2D& rhs_);

// Vector2D*float��2�����Z�q
Vector2D operator * (const Vector2D& lhs_, float rhs_);
Vector2D operator * (float lhs_, const Vector2D& rhs_);
Vector2D operator / (const Vector2D& lhs_, float rhs_);
Vector2D operator / (float lhs_, const Vector2D& rhs_);

// ��r���Z�q
bool operator < (const Vector2D lhs_, const Vector2D rhs_);
bool operator > (const Vector2D lhs_, const Vector2D rhs_);
bool operator <= (const Vector2D lhs_, const Vector2D rhs_);
bool operator >= (const Vector2D lhs_, const Vector2D rhs_);
bool operator == (const Vector2D lhs_, const Vector2D rhs_);
bool operator != (const Vector2D lhs_, const Vector2D rhs_);


#endif // !VECTOR2D_H