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

#pragma region プライベート関数
private:
	void LoadCSV(const char* filePath_);
#pragma endregion

private:
	Library&	m_rLibrary;
	const int	m_mapWidth;
	const int	m_mapHeight;
	const float	m_blockWidth;
	const float	m_blockHeight;

};

#endif // !MAP_H