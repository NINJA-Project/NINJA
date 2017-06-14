/**
* @file	CharacterManager.h
* @breif	CharacterManagerクラスのヘッダ
* @author	ichikawa
*/

#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H

class Player;

class CharacterManager
{
public:
	//コンストラクタ
	CharacterManager();

	//デストラクタ
	~CharacterManager();

	//操作処理
	void Control();

	//描画処理
	void Draw();

private:
#pragma region メンバ変数
	Player* m_pPlayer;
#pragma endregion

	

};
#endif