/**
 * @file	Map.cpp
 * @breif	マップクラス実装
 * @author	shibata
 */

#include "Map.h"
#include <stdio.h>
#include <Library\DebugSystem.h>
#include <Library.h>
#include "../ResourceManager/ResourceManager.h"

Map::Map() : 
m_rLibrary(Library::Instance()),
m_mapWidth(15),
m_mapHeight(20),
m_blockWidth(64.0f),
m_blockHeight(64.0f)
{
	m_rLibrary.SetTexSize(ResourceManager::MainTex::MAP_CHIP, m_blockWidth, m_blockHeight, 0.2f, 0.2f, 0.2f, 0.2f);
	m_rLibrary.SetTexSize(ResourceManager::MainTex::MAP_CHIP, m_blockWidth, m_blockHeight, 0.4f, 0.4f, 0.2f, 0.2f);
	m_rLibrary.SetTexSize(ResourceManager::MainTex::MAP_CHIP, m_blockWidth, m_blockHeight, 0.2f, 0.2f, 0.2f, 0.2f);
}

Map::~Map()
{

}

void Map::Control()
{

}

void Map::Draw()
{

}