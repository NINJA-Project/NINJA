/**
 * @file	Player.h
 * @breif	Playerクラスのヘッダ
 * @author	ichikawa
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <d3dx9.h>

class Library;

class Player
{
public:
	//コンストラクタ
	Player();

	//デストラクタ
	~Player();

	//プレイヤー描画処理
	void Player_Draw();

	//プレイヤー移動処理
	void Player_Move();

	//プレイヤー攻撃処理
	void Player_Attack();

	//プレイヤー影攻撃
	void Player_Shadow_Attack();

private:
	static const float m_DefaultSpeed;

	Library& m_rLibrary;

	//プレイヤー座標	
	D3DXVECTOR2 m_Player_Pos;

	//プレイヤー移動速度変数
	float m_Player_RunSpeed;

	//プレイヤーライフ変数
	int m_Player_Life;
	
	//プレイヤー影攻撃チェック変数
	bool m_Can_Shadow_Attack;
};

#endif 