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
m_rLibrary(Library::Instance()),
m_kWidth(80.0f),
m_kHeight(120.0f),
m_kRunSpeed(5.0f)
{
	m_rLibrary.SetTexSize(ResourceManager::MainTex::Player_Standing1, m_kWidth, m_kHeight, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f);
	
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
		m_Pos.y -= m_kRunSpeed;
	}

	if (m_rLibrary.CheckKey(DIK_S) == ON)
	{
		m_Pos.y += m_kRunSpeed;
	}

	if (m_rLibrary.CheckKey(DIK_A) == ON)
	{
		m_Pos.x -= m_kRunSpeed;
	}

	if (m_rLibrary.CheckKey(DIK_D) == ON)
	{
		m_Pos.x += m_kRunSpeed;
	}
}