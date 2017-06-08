/**
 * @file	ObjectManager.cpp
 * @breif	�o�Ă���I�u�W�F�N�g���Ǘ����Ă���N���X����
 * @author	shibata
 */

#include "ObjectManager.h"
#include "../Map/MapManager.h"
#include <Library\DebugSystem.h>
#include <Library\Define.h>


ObjectManager::ObjectManager() : 
m_pMapManager(New MapManager)
{

}

ObjectManager::~ObjectManager()
{
	SafeDelete(m_pMapManager);
}

void ObjectManager::Control()
{

}

void ObjectManager::Draw()
{
	m_pMapManager->Draw();
}