/**
 * @file	Player.cpp
 * @breif	�v���C���[�N���X�̎���
 * @author	ichikawa
 */

#include "Player.h"
#include "../ResourceManager/ResourceManager.h"
#include <Library.h>


//�R���X�g���N�^
Player::Player():
m_rLibrary(Library::GetInstance()),
m_kWidth(80.0f),
m_kHeight(120.0f),
m_kRunSpeed(5.0f)
{
	m_rLibrary.SetTexSize(ResourceManager::MainTex::PLAYER, PLAYER_STANDING, m_kWidth, m_kHeight, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f);
	
}

//�f�X�g���N�^
Player::~Player()
{

}
//�v���C���[���쏈��
void Player::Control()
{

}

//�v���C���[�`�揈��
void Player::Draw()
{
	m_rLibrary.DrawLeftTop(ResourceManager::MainTex::PLAYER, PLAYER_STANDING, m_Pos.x, m_Pos.y);

}

//�v���C���[�ړ�����
void Player::Move()
{
	if (m_rLibrary.ChooseKey(DIK_W) == ON)
	{
		m_Pos.y -= m_kRunSpeed;
	}

	if (m_rLibrary.ChooseKey(DIK_S) == ON)
	{
		m_Pos.y += m_kRunSpeed;
	}

	if (m_rLibrary.ChooseKey(DIK_A) == ON)
	{
		m_Pos.x -= m_kRunSpeed;
	}

	if (m_rLibrary.ChooseKey(DIK_D) == ON)
	{
		m_Pos.x += m_kRunSpeed;
	}
}