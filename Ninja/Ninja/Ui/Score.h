/**
 * @file	Score.h
 * @breif	スコアクラスヘッダ
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

#pragma region メンバ変数
private:
	int m_currentScore;
#pragma endregion

};


#endif // !SCORE_H