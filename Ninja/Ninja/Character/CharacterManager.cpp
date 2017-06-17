/**
* @file	CharacterManeger.cpp
* @breif	キャラクターマネージャークラスの実装
* @author	ichikawa
*/

#include "CharacterManager.h"
#include "Player.h"
#include <Library\DebugSystem.h>
#include <Library\Define.h>


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
	//Playerの挙動を更新する
	m_pPlayer->Control();
}

void CharacterManager::Draw()
{
	// Playerを描画 ntk
	m_pPlayer->Draw();
}