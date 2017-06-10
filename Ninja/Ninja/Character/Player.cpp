/**
 * @file	Player.cpp
 * @breif	�v���C���[�N���X�̎���
 * @author	ichikawa
 */
#include "Player.h"
#include "../ResourceManager/ResourceManager.h"
#include <Library.h>



const float Player::m_DefaultSpeed = 5.f;


//�R���X�g���N�^
Player::Player():
m_rLibrary(Library::Instance()),
m_Player_Pos(D3DXVECTOR2(0, 0)),
m_Player_RunSpeed(Player::m_DefaultSpeed)
{
	m_rLibrary.SetTexSize(ResourceManager::MainTex::Player_Standing1, 60.0f, 120.0f, 0.5f, 1.0f, 1.0f, 0.0f, 0.0f);
}

//�f�X�g���N�^
Player::~Player()
{

}

//�v���C���[�`�揈��
void Player::Player_Draw()
{
	m_rLibrary.DrawLeftTop(ResourceManager::MainTex::Player_Standing1, m_Player_Pos.x, m_Player_Pos.y);
}

//�v���C���[�ړ�����
void Player::Player_Move()
{
	if (m_rLibrary.CheckKey(DIK_W) == ON)
	{
		m_Player_Pos.x += m_Player_RunSpeed;
	}

	if (m_rLibrary.CheckKey(DIK_S) == ON)
	{
		m_Player_Pos.x -= m_Player_RunSpeed;
	}

	if (m_rLibrary.CheckKey(DIK_A) == ON)
	{
		m_Player_Pos.y -= m_Player_RunSpeed;
	}

	if (m_rLibrary.CheckKey(DIK_D) == ON)
	{
		m_Player_Pos.y += m_Player_RunSpeed;
	}
}