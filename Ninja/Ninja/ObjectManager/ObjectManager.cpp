/**
 * @file	ObjectManager.cpp
 * @breif	�o�Ă���I�u�W�F�N�g���Ǘ����Ă���N���X����
 * @author	shibata
 */
#include <Library\DebugSystem.h>
#include <Library\Define.h>

#include "ObjectManager.h"

ObjectManager::ObjectManager():
m_pCharamanager(New CharacterManager)
{

}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::Control()
{
	m_pCharamanager->Control();
}

void ObjectManager::Draw()
{
	m_pCharamanager->Draw();
}