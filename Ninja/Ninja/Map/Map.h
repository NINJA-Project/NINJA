/**
 * @file	Map.h
 * @breif	マップクラスヘッダ
 * @author	shibata
 */

#ifndef MAP_H
#define MAP_H

class Library;

class Map
{
public:
	Map();
	~Map();

	void Control();
	void Draw();

#pragma region メンバ変数
private:
	Library&	m_rLibrary;
	const int	m_mapWidth;
	const int	m_mapHeight;
	const float	m_blockWidth;
	const float	m_blockHeight;
#pragma endregion
};

#endif // !MAP_H