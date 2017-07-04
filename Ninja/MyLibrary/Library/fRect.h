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
	float top;
	float bottom;
	float left;
	float right;

public:
	fRect();
	fRect(float top_, float bottom_, float left_, float right_);
};

#endif // !FRECT_H