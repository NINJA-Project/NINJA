/**
 * @file	MapManager.cpp
 * @breif	�}�b�v���Ǘ�����N���X����
 * @author	shibata
 */

#include "MapManager.h"
#include "Map.h"
#include <Library\CommoSystem.h>

MapManager::MapManager() : 
m_pMap(New Map)
{

}

MapManager::~MapManager()
{
	SafeDelete(m_pMap);
}

void MapManager::Control()
{

}

void MapManager::Draw()
{
	m_pMap->Draw();
}