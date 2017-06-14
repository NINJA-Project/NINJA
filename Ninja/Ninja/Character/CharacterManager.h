/**
* @file	CharacterManager.h
* @breif	CharacterManager�N���X�̃w�b�_
* @author	ichikawa
*/

#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H

class Player;

class CharacterManager
{
public:
	//�R���X�g���N�^
	CharacterManager();

	//�f�X�g���N�^
	~CharacterManager();

	//���쏈��
	void Control();

	//�`�揈��
	void Draw();

private:
#pragma region �����o�ϐ�
	Player* m_pPlayer;
#pragma endregion

	

};
#endif