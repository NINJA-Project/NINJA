/**
* @file		Score.cpp
* @breif	�X�R�A�N���X����
* @author	shibata
*/

#include "Score.h"
#include "../GameDataManager/GameDataManager.h"

Score::Score()
{
	m_currentScore = m_pGameData->GetScore();
}

Score::~Score()
{
}

void Score::Control()
{
}

void Score::Draw()
{
}
