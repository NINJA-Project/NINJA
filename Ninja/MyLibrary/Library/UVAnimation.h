/**
 * @file	UVAnimation.h
 * @breif	UV�A�j���[�V�����N���X�w�b�_
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


#pragma region �����o�ϐ�
private:
#pragma region �A�j���[�V�����f�[�^�\����
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
#pragma endregion
};

#endif // !UVANIMATION_H