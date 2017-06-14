/**
* @file		Score.cpp
* @breif	スコアクラス実装
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
