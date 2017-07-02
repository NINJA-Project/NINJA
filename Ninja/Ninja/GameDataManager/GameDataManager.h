/**
 * @file	GameDataManager.h
 * @breif	ゲーム上のデータを管理するクラスヘッダ
 * @author	shibata
 */

#ifndef GAMEDATAMANAGER_H
#define GAMEDATAMANAGER_H

/* 
他のクラスから値などを取得したい場合は
このクラスを経由して取得すること
基本インライン関数で実装すること
*/
#include <Library\Singleton.h>


class GameDataManager : public Singleton<GameDataManager>
{
private:
	friend Singleton<GameDataManager>;
	GameDataManager();
	~GameDataManager();

public:
	void SetPlayerLife(const int life_)
	{
		m_playerLife = life_;
	}

	int GetPlayerLife() const
	{
		return m_playerLife;
	}

	void SetScore(const int score_)
	{
		m_currentScore = score_;
	}

	int GetScore() const
	{
		return m_currentScore;
	}

#pragma region メンバ変数
private:
	int m_playerLife;
	int m_currentScore;
#pragma endregion
};

#endif // !GAMEDATAMANAGER_H