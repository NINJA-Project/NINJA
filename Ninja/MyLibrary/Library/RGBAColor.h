/**
 * @file	RGBAColor.h
 * @breif	int�^��RGBA�̒l�����N���X�w�b�_
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

	// @todo ��ɕK�v�ȕ�operator��ǉ�����
};

#endif // !RGBACOLOR_H