/**
 * @file	Vector2D.cpp
 * @breif	2次元ベクトルクラス実装
 * @author	shibata
 */

#include "Vector2D.h"

Vector2D::Vector2D() : 
x(0.0f),
y(0.0f)
{
}

Vector2D::Vector2D(float x_, float y_) : 
x(x_),
y(y_)
{
}

Vector2D& Vector2D::operator=(const Vector2D& vec2D_)
{
	Vector2D vec;
	vec.x = vec2D_.x;
	vec.y = vec2D_.y;
	return *this;
}

Vector2D& Vector2D::operator+=(const Vector2D& vec2D_)
{
	Vector2D vec;
	vec.x += vec2D_.x;
	vec.y += vec2D_.y;
	return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& vec2D_)
{
	Vector2D vec;
	vec.x -= vec2D_.x;
	vec.y -= vec2D_.y;
	return *this;
}

Vector2D& Vector2D::operator*=(const Vector2D& vec2D_)
{
	Vector2D vec;
	vec.x *= vec2D_.x;
	vec.y *= vec2D_.y;
	return *this;
}

Vector2D& Vector2D::operator*=(float lhs_)
{
	Vector2D vec;
	vec.x *= lhs_;
	vec.y *= lhs_;
	return *this;
}

Vector2D& Vector2D::operator/=(const Vector2D& vec2D_)
{
	Vector2D vec;
	vec.x /= vec2D_.x;
	vec.y /= vec2D_.y;
	return *this;
}

Vector2D& Vector2D::operator/=(float lhs_)
{
	Vector2D vec;
	vec.x /= lhs_;
	vec.y /= lhs_;
	return *this;
}

Vector2D& Vector2D::operator++()
{
	Vector2D vec;
	vec.x++;
	vec.y++;
	return *this;
}

Vector2D& Vector2D::operator++(int)
{
	Vector2D vec;
	++vec.x;
	++vec.y;
	return *this;
}

Vector2D& Vector2D::operator--()
{
	Vector2D vec;
	vec.x--;
	vec.y--;
	return *this;
}

Vector2D & Vector2D::operator--(int)
{
	Vector2D vec;
	--vec.x;
	--vec.y;
	return *this;
}

Vector2D operator+(const Vector2D& lhs_, const Vector2D& rhs_)
{
	Vector2D vec;
	vec.x = lhs_.x + rhs_.x;
	vec.y = lhs_.y + rhs_.y;
	return vec;
}

Vector2D operator-(const Vector2D& lhs_, const Vector2D& rhs_)
{
	Vector2D vec;
	vec.x = lhs_.x - rhs_.x;
	vec.y = lhs_.y - rhs_.y;
	return vec;
}

Vector2D operator*(const Vector2D& lhs_, const Vector2D& rhs_)
{
	Vector2D vec;
	vec.x = lhs_.x * rhs_.x;
	vec.y = lhs_.y * rhs_.y;
	return vec;
}

Vector2D operator/(const Vector2D& lhs_, const Vector2D& rhs_)
{
	Vector2D vec;
	vec.x = lhs_.x / rhs_.x;
	vec.y = lhs_.y / rhs_.y;
	return vec;
}

Vector2D operator*(const Vector2D& lhs_, float rhs_)
{
	Vector2D vec;
	vec.x = lhs_.x * rhs_;
	vec.y = lhs_.y * rhs_;
	return vec;
}

Vector2D operator*(float lhs_, const Vector2D& rhs_)
{
	Vector2D vec;
	vec.x = lhs_ * rhs_.x;
	vec.y = lhs_ * rhs_.y;
	return vec;
}

Vector2D operator/(const Vector2D& lhs_, float rhs_)
{
	Vector2D vec;
	vec.x = lhs_.x / rhs_;
	vec.y = lhs_.y / rhs_;
	return vec;
}

Vector2D operator/(float lhs_, const Vector2D& rhs_)
{
	Vector2D vec;
	vec.x = lhs_ / rhs_.x;
	vec.y = lhs_ / rhs_.y;
	return vec;
}

bool operator<(const Vector2D lhs_, const Vector2D rhs_)
{
	return (lhs_.x < rhs_.x && lhs_.y < rhs_.y);
}

bool operator>(const Vector2D lhs_, const Vector2D rhs_)
{
	return (lhs_.x > rhs_.x && lhs_.y > rhs_.y);
}

bool operator<=(const Vector2D lhs_, const Vector2D rhs_)
{
	return (lhs_.x <= rhs_.x && lhs_.y <= rhs_.y);
}

bool operator>=(const Vector2D lhs_, const Vector2D rhs_)
{
	return (lhs_.x >= rhs_.x && lhs_.y >= rhs_.y);
}

bool operator==(const Vector2D lhs_, const Vector2D rhs_)
{
	return (lhs_.x == rhs_.x && lhs_.y == rhs_.y);
}

bool operator!=(const Vector2D lhs_, const Vector2D rhs_)
{
	return (lhs_.x != rhs_.x && lhs_.y != rhs_.y);
}
