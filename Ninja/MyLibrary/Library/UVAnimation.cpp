/**
* @file		UVAnimation.h
* @breif	UVアニメーションクラス実装
* @author	shibata
*/


#include "UVAnimation.h"
#include "CommoSystem.h"

namespace
{
	fRect InitUV = { 0.0f,0.0f,0.0f,0.0f };
}

UVAnimation::UVAnimation() : 
m_isReverse(false),
m_currentFlame(0),
m_currntAnimeData(InitUV, 0)
{
}

UVAnimation::~UVAnimation()
{
}

void UVAnimation::CreateAnimationData(int tuCount_, int tvCount_, const fRect moveUVval_, float changeFlameTime_)
{
}

bool UVAnimation::UpData()
{
	++m_currentFlame;
	return true;
}

void UVAnimation::SetAnimetionData(int animeNum_, bool isReverse_)
{
	m_isReverse = isReverse_;

	for (int i = 0; i < animeNum_; ++i)
	{
		m_animeNumber.emplace_back(i);
	}
}