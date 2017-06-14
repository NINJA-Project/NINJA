/**
 * @file	ObjectManager.cpp
 * @breif	出てくるオブジェクトを管理しているクラス実装
 * @author	shibata
 */


#include "ObjectManager.h"
#include "../Map/MapManager.h"
#include "../Character/CharacterManager.h"
#include <Library\DebugSystem.h>
#include <Library\Define.h>

ObjectManager::ObjectManager():
m_pMapManager(New MapManager),
m_pCharamanager(New CharacterManager)
{

}

ObjectManager::~ObjectManager()
{
	SafeDelete(m_pMapManager);
}

void ObjectManager::Control()
{
	m_pCharamanager->Control();
}

void ObjectManager::Draw()
{
	m_pCharamanager->Draw();
	m_pMapManager->Draw();
}