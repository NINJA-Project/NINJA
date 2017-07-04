/**
* @file		Vector3D.h
* @breif	3次元ベクトルクラスヘッダ
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

	// 代入演算子
	Vector3D& operator  = (const Vector3D& vec2D_);

	// 複合代入演算子
	Vector3D& operator += (const Vector3D& vec2D_);
	Vector3D& operator -= (const Vector3D& vec2D_);
	Vector3D& operator *= (const Vector3D& vec2D_);
	Vector3D& operator *= (float lhs_);
	Vector3D& operator /= (const Vector3D& vec2D_);
	Vector3D& operator /= (float lhs_);

	// 前置インクリメント
	Vector3D& operator ++ ();
	// 後置インクリメント
	Vector3D& operator ++ (int);

	// 前置デクリメント
	Vector3D& operator -- ();
	// 後置デクリメント
	Vector3D& operator -- (int);

};

// Vector3D同士の2項演算子
Vector3D operator + (const Vector3D& lhs_, const Vector3D& rhs_);
Vector3D operator - (const Vector3D& lhs_, const Vector3D& rhs_);
Vector3D operator * (const Vector3D& lhs_, const Vector3D& rhs_);
Vector3D operator / (const Vector3D& lhs_, const Vector3D& rhs_);

// Vector3D*floatの2項演算子
Vector3D operator * (const Vector3D& lhs_, float rhs_);
Vector3D operator * (float lhs_, const Vector3D& rhs_);
Vector3D operator / (const Vector3D& lhs_, float rhs_);
Vector3D operator / (float lhs_, const Vector3D& rhs_);

// 比較演算子
bool operator < (const Vector3D lhs_, const Vector3D rhs_);
bool operator > (const Vector3D lhs_, const Vector3D rhs_);
bool operator <= (const Vector3D lhs_, const Vector3D rhs_);
bool operator >= (const Vector3D lhs_, const Vector3D rhs_);
bool operator == (const Vector3D lhs_, const Vector3D rhs_);
bool operator != (const Vector3D lhs_, const Vector3D rhs_);


#endif // !VECTOR3D_H