/**
 * @file	UVAnimation.h
 * @breif	UVアニメーションクラスヘッダ
 * @author	shibata
 */

#ifndef UVANIMATION_H
#define UVANIMATION_H

#include "fRect.h"
#include <vector>

class UVAnimation
{
public:
	UVAnimation();
	~UVAnimation();

	void SetAnimaData(const fRect& texUV_, int animationNum_);

	const fRect& GetCurrentUV() const
	{
		return m_currentAnimaData.m_texUV;
	}

#pragma region メンバ変数
private:
#pragma region アニメーションデータ構造体
	struct AnimaData
	{
		fRect	m_texUV;
		int		m_flameCount;

		AnimaData() :
			m_texUV(0.0f, 0.0f, 0.0f, 0.0f),
			m_flameCount(0)
		{}
	};
#pragma endregion
	std::vector<AnimaData>	m_animationData;
	std::vector<int>		m_animationNumber;
	AnimaData				m_currentAnimaData;
#pragma endregion
};

#endif // !UVANIMATION_H