/**
* @file		RGBAColor.cpp
* @breif	int型のRGBAの値をもつクラス実装
* @author	shibata
*/

#include "RGBAColor.h"

RGBAColor::RGBAColor() : 
r(0),
g(0),
b(0),
a(0)
{
}

RGBAColor::RGBAColor(int r_, int g_, int b_) :
r(r_),
g(g_),
b(b_),
a(0)
{
}

RGBAColor::RGBAColor(int r_, int g_, int b_, int a_) : 
r(r_),
g(g_),
b(b_),
a(a_)
{
}