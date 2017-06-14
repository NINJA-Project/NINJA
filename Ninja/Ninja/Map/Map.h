/**
 * @file	Map.h
 * @breif	マップクラスヘッダ
 * @author	shibata
 */

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

class Library;

class Map
{
public:
	Map();
	~Map();

	void Control();
	void Draw();

	enum
	{
		MAP_CHIP1,
		MAP_CHIP2,
		MAP_CHIP3,
	};

private:
#pragma region メンバ変数
	Library&								m_rLibrary;
	std::vector<std::vector<std::string>>	m_csvData;
	const float								m_kBlockWidth;
	const float								m_kBlockHeight;
#pragma endregion
};

#endif // !MAP_H