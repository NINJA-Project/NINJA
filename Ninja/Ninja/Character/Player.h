/**
 * @file	Player.h
 * @breif	Player�N���X�̃w�b�_
 * @author	ichikawa
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <d3dx9.h>

class Library;

class Player
{
public:
	//�R���X�g���N�^
	Player();

	//�f�X�g���N�^
	~Player();

	//�v���C���[�`�揈��
	void Player_Draw();

	//�v���C���[�ړ�����
	void Player_Move();

	//�v���C���[�U������
	void Player_Attack();

	//�v���C���[�e�U��
	void Player_Shadow_Attack();

private:
	static const float m_DefaultSpeed;

	Library& m_rLibrary;

	//�v���C���[���W	
	D3DXVECTOR2 m_Player_Pos;

	//�v���C���[�ړ����x�ϐ�
	float m_Player_RunSpeed;

	//�v���C���[���C�t�ϐ�
	int m_Player_Life;
	
	//�v���C���[�e�U���`�F�b�N�ϐ�
	bool m_Can_Shadow_Attack;
};

#endif 