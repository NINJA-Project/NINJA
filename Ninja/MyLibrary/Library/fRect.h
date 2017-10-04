/**
 * @file	fRect.h
 * @breif	floatのRectクラスヘッダ
 * @author	shibata
 */


#ifndef FRECT_H
#define FRECT_H

class fRect
{
public:
	float leftTop;
	float rightTop;
	float leftBottom;
	float rightBottom;

public:
	fRect();
	fRect(float leftTop_, float rightTop_, float leftBottom_, float rightBottom_);

	fRect& operator += (const fRect& vec2D_);

};

#endif // !FRECT_H