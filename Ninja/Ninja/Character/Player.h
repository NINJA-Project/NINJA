/**
 * @file	Player.h
 * @breif	Player�N���X�̃w�b�_
 * @author	ichikawa
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <d3dx9.h>
#include "Character.h"

class Library;

class Player : public Character
{
public:
	//�R���X�g���N�^
	Player();

	//�f�X�g���N�^
	~Player();

	//�v���C���[�`�揈��
	void Draw();

	//�v���C���[����
	void Control();

	//�v���C���[�ړ�����
	void Move();

private:
	Library& m_rLibrary;
	
	//�v���C���[�e�U���`�F�b�N�ϐ�
	bool m_CanShadowAttack;



	//�v���C���[�U������
	void Attack();

	//�v���C���[�e�U��
	void ShadowAttack();

	//�v���C���[����
	const float m_kHeight;

	//�v���C���[����
	const float m_kWidth;

	//�ړ����x�ϐ�
	const float m_kRunSpeed;

	enum PlayerTex
	{
		PLAYER_STANDING
	};
};

#endif 