/**
 * @file	Vector2D.h
 * @breif	2次元ベクトルクラスヘッダ
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

	// 代入演算子
	Vector2D& operator  = (const Vector2D& vec2D_);

	// 複合代入演算子
	Vector2D& operator += (const Vector2D& vec2D_);
	Vector2D& operator -= (const Vector2D& vec2D_);
	Vector2D& operator *= (const Vector2D& vec2D_);
	Vector2D& operator *= (float lhs_);
	Vector2D& operator /= (const Vector2D& vec2D_);
	Vector2D& operator /= (float lhs_);

	// 前置インクリメント
	Vector2D& operator ++ ();
	// 後置インクリメント
	Vector2D& operator ++ (int);

	// 前置デクリメント
	Vector2D& operator -- ();
	// 後置デクリメント
	Vector2D& operator -- (int);

};

// Vector2D同士の2項演算子
Vector2D operator + (const Vector2D& lhs_, const Vector2D& rhs_);
Vector2D operator - (const Vector2D& lhs_, const Vector2D& rhs_);
Vector2D operator * (const Vector2D& lhs_, const Vector2D& rhs_);
Vector2D operator / (const Vector2D& lhs_, const Vector2D& rhs_);

// Vector2D*floatの2項演算子
Vector2D operator * (const Vector2D& lhs_, float rhs_);
Vector2D operator * (float lhs_, const Vector2D& rhs_);
Vector2D operator / (const Vector2D& lhs_, float rhs_);
Vector2D operator / (float lhs_, const Vector2D& rhs_);

// 比較演算子
bool operator < (const Vector2D lhs_, const Vector2D rhs_);
bool operator > (const Vector2D lhs_, const Vector2D rhs_);
bool operator <= (const Vector2D lhs_, const Vector2D rhs_);
bool operator >= (const Vector2D lhs_, const Vector2D rhs_);
bool operator == (const Vector2D lhs_, const Vector2D rhs_);
bool operator != (const Vector2D lhs_, const Vector2D rhs_);


#endif // !VECTOR2D_H