/**
* @file		Life.cpp
* @breif	�v���C���[�̃��C�t�N���X����
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
