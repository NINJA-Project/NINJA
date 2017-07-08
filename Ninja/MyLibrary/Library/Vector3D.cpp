/**
* @file		Vector3D.cpp
* @breif	3次元ベクトルクラス実装
* @author	shibata
*/

#include "Vector3D.h"

Vector3D::Vector3D() :
x(0.0f),
y(0.0f),
z(0.0f)
{
}

Vector3D::Vector3D(float x_, float y_, float z_) :
x(x_),
y(y_),
z(z_)
{
}

Vector3D& Vector3D::operator=(const Vector3D& vec2D_)
{
	Vector3D vec;
	vec.x = vec2D_.x;
	vec.y = vec2D_.y;
	vec.z = vec2D_.z;
	return *this;
}

Vector3D& Vector3D::operator+=(const Vector3D& vec2D_)
{
	Vector3D vec;
	vec.x += vec2D_.x;
	vec.y += vec2D_.y;
	vec.z += vec2D_.z;

	return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& vec2D_)
{
	Vector3D vec;
	vec.x -= vec2D_.x;
	vec.y -= vec2D_.y;
	vec.z -= vec2D_.z;
	return *this;
}

Vector3D& Vector3D::operator*=(const Vector3D& vec2D_)
{
	Vector3D vec;
	vec.x *= vec2D_.x;
	vec.y *= vec2D_.y;
	vec.z *= vec2D_.z;
	return *this;
}

Vector3D& Vector3D::operator*=(float lhs_)
{
	Vector3D vec;
	vec.x *= lhs_;
	vec.y *= lhs_;
	vec.z *= lhs_;
	return *this;
}

Vector3D& Vector3D::operator/=(const Vector3D& vec2D_)
{
	Vector3D vec;
	vec.x /= vec2D_.x;
	vec.y /= vec2D_.y;
	vec.z /= vec2D_.z;
	return *this;
}

Vector3D& Vector3D::operator/=(float lhs_)
{
	Vector3D vec;
	vec.x /= lhs_;
	vec.y /= lhs_;
	vec.z /= lhs_;
	return *this;
}

Vector3D& Vector3D::operator++()
{
	Vector3D vec;
	vec.x++;
	vec.y++;
	vec.z++;
	return *this;
}

Vector3D& Vector3D::operator++(int)
{
	Vector3D vec;
	++vec.x;
	++vec.y;
	++vec.z;
	return *this;
}

Vector3D& Vector3D::operator--()
{
	Vector3D vec;
	vec.x--;
	vec.y--;
	vec.z--;
	return *this;
}

Vector3D & Vector3D::operator--(int)
{
	Vector3D vec;
	--vec.x;
	--vec.y;
	--vec.z;
	return *this;
}

Vector3D operator+(const Vector3D& lhs_, const Vector3D& rhs_)
{
	Vector3D vec;
	vec.x = lhs_.x + rhs_.x;
	vec.y = lhs_.y + rhs_.y;
	vec.z = lhs_.z + rhs_.z;
	return vec;
}

Vector3D operator-(const Vector3D& lhs_, const Vector3D& rhs_)
{
	Vector3D vec;
	vec.x = lhs_.x - rhs_.x;
	vec.y = lhs_.y - rhs_.y;
	vec.z = lhs_.z - rhs_.z;
	return vec;
}

Vector3D operator*(const Vector3D& lhs_, const Vector3D& rhs_)
{
	Vector3D vec;
	vec.x = lhs_.x * rhs_.x;
	vec.y = lhs_.y * rhs_.y;
	vec.z = lhs_.z * rhs_.z;
	return vec;
}

Vector3D operator/(const Vector3D& lhs_, const Vector3D& rhs_)
{
	Vector3D vec;
	vec.x = lhs_.x / rhs_.x;
	vec.y = lhs_.y / rhs_.y;
	vec.z = lhs_.z / rhs_.z;
	return vec;
}

Vector3D operator*(const Vector3D& lhs_, float rhs_)
{
	Vector3D vec;
	vec.x = lhs_.x * rhs_;
	vec.y = lhs_.y * rhs_;
	vec.z = lhs_.z * rhs_;
	return vec;
}

Vector3D operator*(float lhs_, const Vector3D& rhs_)
{
	Vector3D vec;
	vec.x = lhs_ * rhs_.x;
	vec.y = lhs_ * rhs_.y;
	vec.z = lhs_ * rhs_.z;
	return vec;
}

Vector3D operator/(const Vector3D& lhs_, float rhs_)
{
	Vector3D vec;
	vec.x = lhs_.x / rhs_;
	vec.y = lhs_.y / rhs_;
	vec.z = lhs_.z / rhs_;
	return vec;
}

Vector3D operator/(float lhs_, const Vector3D& rhs_)
{
	Vector3D vec;
	vec.x = lhs_ / rhs_.x;
	vec.y = lhs_ / rhs_.y;
	vec.z = lhs_ / rhs_.z;
	return vec;
}

bool operator<(const Vector3D lhs_, const Vector3D rhs_)
{
	return (lhs_.x < rhs_.x && lhs_.y < rhs_.y && lhs_.z < rhs_.z);
}

bool operator>(const Vector3D lhs_, const Vector3D rhs_)
{
	return (lhs_.x > rhs_.x && lhs_.y > rhs_.y && lhs_.z > rhs_.z);
}

bool operator<=(const Vector3D lhs_, const Vector3D rhs_)
{
	return (lhs_.x <= rhs_.x && lhs_.y <= rhs_.y && lhs_.z <= rhs_.z);
}

bool operator>=(const Vector3D lhs_, const Vector3D rhs_)
{
	return (lhs_.x >= rhs_.x && lhs_.y >= rhs_.y && lhs_.z >= rhs_.z);
}

bool operator==(const Vector3D lhs_, const Vector3D rhs_)
{
	return (lhs_.x == rhs_.x && lhs_.y == rhs_.y && lhs_.z == rhs_.z);
}

bool operator!=(const Vector3D lhs_, const Vector3D rhs_)
{
	return (lhs_.x != rhs_.x && lhs_.y != rhs_.y && lhs_.z != rhs_.z);
}
