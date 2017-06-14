/**
 * @file	Player.cpp
 * @breif	プレイヤークラスの実装
 * @author	ichikawa
 */

#include "Player.h"
#include "../ResourceManager/ResourceManager.h"
#include <Library.h>


//コンストラクタ
Player::Player():
m_rLibrary(Library::Instance())
{
	m_rLibrary.SetTexSize(ResourceManager::MainTex::Player_Standing1, 60.0f, 120.0f, 0.5f, 1.0f, 1.0f, 0.0f, 0.0f);
}

//デストラクタ
Player::~Player()
{

}
//プレイヤー操作処理
void Player::Control()
{

}

//プレイヤー描画処理
void Player::Draw()
{
	m_rLibrary.DrawLeftTop(ResourceManager::MainTex::Player_Standing1, m_Pos.x, m_Pos.y);

}

//プレイヤー移動処理
void Player::Move()
{
	if (m_rLibrary.CheckKey(DIK_W) == ON)
	{
		m_Pos.x += m_RunSpeed;
	}

	if (m_rLibrary.CheckKey(DIK_S) == ON)
	{
		m_Pos.x -= m_RunSpeed;
	}

	if (m_rLibrary.CheckKey(DIK_A) == ON)
	{
		m_Pos.y -= m_RunSpeed;
	}

	if (m_rLibrary.CheckKey(DIK_D) == ON)
	{
		m_Pos.y += m_RunSpeed;
	}
}