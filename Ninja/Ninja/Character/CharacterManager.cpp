/**
* @file	CharacterManeger.cpp
* @breif	キャラクターマネージャークラスの実装
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
	//Playerの挙動を更新する
	m_pPlayer->Control();
}

void CharacterManager::Draw()
{
	// Playerを描画 ntk
	m_pPlayer->Draw();
}