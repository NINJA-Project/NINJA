/**
* @file	Character.h
* @breif	Characterクラスのヘッダ
* @author	ichikawa
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <d3dx9.h>

class Character
{
public:
	//コンストラクタ
	Character();

	//デストラクタ
	~Character();

	//操作処理
	void Control();

	//描画処理
	void Draw();

private:

protected:
	//プレイヤー座標	
	D3DXVECTOR2 m_Pos;

	//ライフ変数
	int m_Life;
};

#endif