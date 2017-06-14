/**
 * @file	Score.h
 * @breif	�X�R�A�N���X�w�b�_
 * @author	shibata
 */

#ifndef SCORE_H
#define SCORE_H

#include "Ui.h"

class Score : public Ui
{
public:
	Score();
	~Score();

	virtual void Control();
	virtual void Draw();

#pragma region �����o�ϐ�
private:
	int m_currentScore;
#pragma endregion

};


#endif // !SCORE_H