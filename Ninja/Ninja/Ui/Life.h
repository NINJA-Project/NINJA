/**
 * @file	Life.h
 * @breif	プレイヤーのライフクラスヘッダ
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

#pragma region メンバ変数
private:
	int m_playerLife;
#pragma endregion


};

#endif // LIFE_H