/**
* @file		fRect.cpp
* @breif	float‚ÌRectƒNƒ‰ƒXŽÀ‘•
* @author	shibata
*/

#include "fRect.h"

fRect::fRect() :
leftTop(0.0f),
rightTop(0.0f),
leftBottom(0.0f),
rightBottom(0.0f)
{
}

fRect::fRect(float leftTop_, float rightTop_, float leftBottom_, float rightBottom_) :
rightTop(rightTop_),
rightBottom(rightBottom_),
leftTop(leftTop_),
leftBottom(leftBottom_)
{
}

fRect& fRect::operator+=(const fRect& rect_)
{
	fRect rect;
	rect.leftTop += rect_.leftTop;
	rect.rightTop += rect_.rightTop;
	rect.leftBottom += rect_.leftBottom;
	rect.rightBottom += rect_.rightBottom;
	return *this;
}
