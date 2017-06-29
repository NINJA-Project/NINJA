/**
* @file	Character.h
* @breif	Character�N���X�̃w�b�_
* @author	ichikawa
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <d3dx9.h>

class Character
{
public:
	//�R���X�g���N�^
	Character();

	//�f�X�g���N�^
	~Character();

	//���쏈��
	void Control();

	//�`�揈��
	void Draw();

private:

protected:
	//�v���C���[���W	
	D3DXVECTOR2 m_Pos;

	//���C�t�ϐ�
	int m_Life;
};

#endif