/**
 * @file	Map.h
 * @breif	マップクラスヘッダ
 * @author	shibata
 */

#ifndef MAP_H
#define MAP_H

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

};

#endif // !MAP_H