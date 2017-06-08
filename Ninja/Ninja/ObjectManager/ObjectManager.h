/**
 * @file	ObjectManager.h
 * @breif	�o�Ă���I�u�W�F�N�g���Ǘ����Ă���N���X�w�b�_
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