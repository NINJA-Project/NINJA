/**
 * @file	ObjectManager.h
 * @breif	出てくるオブジェクトを管理しているクラスヘッダ
 * @author	shibata
 */
#include"../Character/CharacterManager.h"

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Control();
	void Draw();

private:
	CharacterManager* m_pCharamanager;

};

#endif // !OBJECTMANAGER_H