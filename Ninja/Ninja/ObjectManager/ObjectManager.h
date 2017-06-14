/**
 * @file	ObjectManager.h
 * @breif	ゲーム上のオブジェクトを管理するクラスヘッダ
 * @author	shibata
 */

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

class MapManager;
class CharacterManager;

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Control();
	void Draw();

private:
	MapManager*	m_pMapManager;
	CharacterManager* m_pCharamanager;
};

#endif // !OBJECTMANAGER_H