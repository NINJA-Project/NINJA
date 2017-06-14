/**
* @file		Life.cpp
* @breif	プレイヤーのライフクラス実装
* @author	shibata
*/


#include "Life.h"
#include "../GameDataManager/GameDataManager.h"

Life::Life()
{
	m_playerLife = m_pGameData->GetPlayerLife();
}

Life::~Life()
{
}

void Life::Control()
{
}

void Life::Draw()
{
}
