/**
 * @file	RGBAColor.h
 * @breif	int型のRGBAの値をもつクラスヘッダ
 * @author	shibata
 */

#ifndef RGBACOLOR_H
#define RGBACOLOR_H

class RGBAColor
{
public:
	int r;
	int g;
	int b;
	int a;

public:
	RGBAColor();
	RGBAColor(int r_, int g_, int b_);
	RGBAColor(int r_, int g_, int b_, int a_);
	~RGBAColor();

	// @todo 後に必要な分operatorを追加する
};

#endif // !RGBACOLOR_H