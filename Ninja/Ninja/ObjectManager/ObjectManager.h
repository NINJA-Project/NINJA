/**
 * @file	ObjectManager.h
 * @breif	�o�Ă���I�u�W�F�N�g���Ǘ����Ă���N���X�w�b�_
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