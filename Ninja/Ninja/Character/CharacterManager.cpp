/**
* @file	CharacterManeger.cpp
* @breif	�L�����N�^�[�}�l�[�W���[�N���X�̎���
* @author	ichikawa
*/

#include "CharacterManager.h"
#include "Player.h"
#include <Library\CommoSystem.h>


CharacterManager::CharacterManager() : 
m_pPlayer(New Player)
{

}

CharacterManager::~CharacterManager()
{
	SafeDelete(m_pPlayer);
}

void CharacterManager::Control()
{
	//Player�̋������X�V����
	m_pPlayer->Control();

	m_pPlayer->Move();
}

void CharacterManager::Draw()
{
	// Player��`��
	m_pPlayer->Draw();
}