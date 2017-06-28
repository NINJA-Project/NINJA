/**
 * @file	MapManager.cpp
 * @breif	マップを管理するクラス実装
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