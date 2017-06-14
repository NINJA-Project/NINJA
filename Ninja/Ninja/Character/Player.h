/**
 * @file	Player.h
 * @breif	Playerクラスのヘッダ
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
	//コンストラクタ
	Player();

	//デストラクタ
	~Player();

	//プレイヤー描画処理
	void Draw();

	//プレイヤー操作
	void Control();

private:
	Library& m_rLibrary;
	
	//プレイヤー影攻撃チェック変数
	bool m_CanShadowAttack;

	//プレイヤー移動処理
	void Move();

	//プレイヤー攻撃処理
	void Attack();

	//プレイヤー影攻撃
	void ShadowAttack();
};

#endif 