/**
 * @file	Map.h
 * @breif	マップクラスヘッダ
 * @author	shibata
 */

#ifndef MAP_H
#define MAP_H

class Library;
class GameDataManager;

class Map
{
public:
	Map();
	~Map();

	void Control();
	void Draw();

private:
#pragma region メンバ変数
	Library&			m_rLibrary;
	GameDataManager*	m_pGameData;
	const int			m_kMapWidth;
	const int			m_kMapHeight;
	const float			m_kBlockWidth;
	const float			m_kBlockHeight;
	int**				m_ppMap;
#pragma endregion
};

#endif // !MAP_H