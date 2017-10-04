/**
* @file		UVAnimationManager.cpp
* @breif	�A�j���[�V�����N���X�̊Ǘ��N���X����
* @author	shibata
*/

#include "UVAnimationManager.h"
#include "UVAnimation.h"

UVAnimationManager::UVAnimationManager()
{
}

UVAnimationManager::~UVAnimationManager()
{
}

bool UVAnimationManager::UpData(int drawIndex_)
{
	return m_pUVAnimation[drawIndex_]->UpData();
}

void UVAnimationManager::SetAnimetionData(int drawIndex_, int animeNum_, bool isReverse_)
{
	m_pUVAnimation[drawIndex_]->SetAnimetionData(animeNum_, isReverse_);
}

fRect UVAnimationManager::GetRect(int drawIndex_)
{
	return m_pUVAnimation[drawIndex_]->GetRect();
}
