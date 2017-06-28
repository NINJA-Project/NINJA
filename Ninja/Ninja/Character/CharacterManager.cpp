/**
* @file	CharacterManeger.cpp
* @breif	�L�����N�^�[�}�l�[�W���[�N���X�̎���
* @author	ichikawa
*/

#include "CharacterManager.h"
#include "Player.h"
#include <Library\CommoSystem.h>


CharacterManager::CharacterManager():
m_pPlayer(New Player)
{

}

CharacterManager::~CharacterManager()
{

}

void CharacterManager::Control()
{
	//Player�̋������X�V����
	m_pPlayer->Control();
}

void CharacterManager::Draw()
{
	// Player��`�� ntk
	m_pPlayer->Draw();
}