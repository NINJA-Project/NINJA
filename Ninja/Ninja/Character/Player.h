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

	//プレイヤー移動処理
	void Move();

private:
	Library& m_rLibrary;
	
	//プレイヤー影攻撃チェック変数
	bool m_CanShadowAttack;



	//プレイヤー攻撃処理
	void Attack();

	//プレイヤー影攻撃
	void ShadowAttack();

	//プレイヤー高さ
	const float m_kHeight;

	//プレイヤー横幅
	const float m_kWidth;

	//移動速度変数
	const float m_kRunSpeed;

	enum PlayerTex
	{
		PLAYER_STANDING
	};
};

#endif 