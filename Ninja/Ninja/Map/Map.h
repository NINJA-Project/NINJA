/**
 * @file	Map.h
 * @breif	�}�b�v�N���X�w�b�_
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

#pragma region �v���C�x�[�g�֐�
private:
	void LoadCSV(const char* filePath_);
#pragma endregion

};

#endif // !MAP_H