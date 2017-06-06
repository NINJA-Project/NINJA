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
	virtual ~GameDataManager();

public:

};


#endif // !GAMEDATAMANAGER_H