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
	Player* p_mPlayer;
#pragma endregion

	int player;

};
#endif