/**
 * @file	Life.h
 * @breif	�v���C���[�̃��C�t�N���X�w�b�_
 * @author	shibata
 */

#ifndef LIFE_H
#define LIFE_H

#include "Ui.h"

class Life : public Ui
{
public:
	Life();
	~Life();

	virtual void Control();
	virtual void Draw();

#pragma region �����o�ϐ�
private:
	int m_playerLife;
#pragma endregion


};

#endif // LIFE_H