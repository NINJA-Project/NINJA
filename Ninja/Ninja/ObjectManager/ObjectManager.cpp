/**
 * @file	ObjectManager.cpp
 * @breif	出てくるオブジェクトを管理しているクラス実装
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