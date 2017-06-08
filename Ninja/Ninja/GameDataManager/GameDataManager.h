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
#include <vector>

class GameDataManager : public Singleton<GameDataManager>
{
private:
	friend Singleton<GameDataManager>;
	GameDataManager();
	virtual ~GameDataManager();

public:
	void SetCsvWidth(const int width_)
	{
		m_csvWidth = width_;
	}

	int GetCsvWidth() const
	{
		return m_csvWidth;
	}

	void SetCsvHeight(const int height_)
	{
		m_csvHeight = height_;
	}

	int GetCsvHeight() const
	{
		return m_csvHeight;
	}

private:
#pragma region メンバ変数
	int m_csvWidth;
	int m_csvHeight;
	
#pragma endregion
};

#endif // !GAMEDATAMANAGER_H