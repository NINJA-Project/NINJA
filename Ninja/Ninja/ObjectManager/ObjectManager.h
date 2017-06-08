/**
 * @file	ObjectManager.h
 * @breif	出てくるオブジェクトを管理しているクラスヘッダ
 * @author	shibata
 */

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

class MapManager;

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Control();
	void Draw();

private:
	MapManager*	m_pMapManager;

};

#endif // !OBJECTMANAGER_H