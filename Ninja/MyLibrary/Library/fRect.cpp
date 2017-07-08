/**
* @file		fRect.cpp
* @breif	float‚ÌRectƒNƒ‰ƒXŽÀ‘•
* @author	shibata
*/

#include "fRect.h"

fRect::fRect() :
top(0.0f),
bottom(0.0f),
left(0.0f),
right(0.0f)
{
}

fRect::fRect(float top_, float bottom_, float left_, float right_) : 
top(top_),
bottom(bottom_),
left(left_),
right(right_)
{
}