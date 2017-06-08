/**
 * @file	Map.h
 * @breif	�}�b�v�N���X�w�b�_
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

#pragma region �����o�ϐ�
private:
	Library&	m_rLibrary;
	const int	m_kMapWidth;
	const int	m_kMapHeight;
	const float	m_kBlockWidth;
	const float	m_kBlockHeight;
#pragma endregion
};

#endif // !MAP_H