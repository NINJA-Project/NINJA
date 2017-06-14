/**
 * @file	MapManager.h
 * @breif	�}�b�v���Ǘ�����N���X�w�b�_
 * @author	shibata
 */

#ifndef MAPMANAGER_H
#define MAPMANAGER_H

class Map;

class MapManager
{
public:
	MapManager();
	~MapManager();

	void Control();
	void Draw();

private:
	Map*	m_pMap;
};

#endif // !MAPMANAGER_H