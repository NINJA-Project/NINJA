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
#include "../GameDataManager/GameDataManager.h"

Map::Map() : 
m_rLibrary(Library::Instance()),
m_pGameData(&GameDataManager::Instance()),
m_kMapWidth(15),
m_kMapHeight(20),
m_kBlockWidth(64.0f),
m_kBlockHeight(64.0f)
{

	m_rLibrary.SetTexSize(ResourceManager::MainTex::MAP_CHIP, m_kBlockWidth, m_kBlockHeight, 0.2f, 0.2f, 0.2f, 0.2f);
	m_rLibrary.SetTexSize(ResourceManager::MainTex::MAP_CHIP, m_kBlockWidth, m_kBlockHeight, 0.4f, 0.4f, 0.2f, 0.2f);
	m_rLibrary.SetTexSize(ResourceManager::MainTex::MAP_CHIP, m_kBlockWidth, m_kBlockHeight, 0.6f, 0.6f, 0.4f, 0.4f);
	m_ppMap = m_pGameData->GetMapArray();
}

Map::~Map()
{

}

void Map::Control()
{

}

void Map::Draw()
{
	for (int y = 0; y < m_pGameData->GetCsvHeight() -1; y++)
	{
		for (int x = 0; x < m_pGameData->GetCsvWidth() - 1; x++)
		{
			if (m_ppMap[y][x] == ResourceManager::ChipID::NORMAL_BLOCK)
			{
				m_rLibrary.DrawCenter(ResourceManager::MainTex::MAP_CHIP, (x * m_kBlockWidth), (y * m_kBlockHeight));
			}
		}
	}
}