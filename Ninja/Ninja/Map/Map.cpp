/**
 * @file	Map.cpp
 * @breif	マップクラス実装
 * @author	shibata
 */

#include "Map.h"
#include <stdio.h>
#include <Library\CommoSystem.h>
#include <Library.h>
#include "../ResourceManager/ResourceManager.h"
#include <iostream>

Map::Map() : 
m_rLibrary(Library::GetInstance()),
m_kBlockWidth(64.0f),
m_kBlockHeight(64.0f)
{
	ResourceManager* mapLoad = New ResourceManager;
	if (!mapLoad->CSVLoader(m_csvData))
	{
#if _DEBUG
		MyAssert(mapLoad, "csvデータが読み込まれていません");
#endif // _DEBUG
	}
	m_rLibrary.SetTexSize(ResourceManager::MainTex::MAP_CHIP, NORMAL_BLOCK, m_kBlockWidth, m_kBlockHeight, 0.25f, 1.0f, 0.0f, 0.0f);
	m_rLibrary.SetTexSize(ResourceManager::MainTex::MAP_CHIP, LANDING_BLOCK, m_kBlockWidth, m_kBlockHeight, 0.5f, 1.0f, 0.25f, 0.0f);
	m_rLibrary.SetTexSize(ResourceManager::MainTex::MAP_CHIP, LANDING_BLOCK2, m_kBlockWidth, m_kBlockHeight, 0.75f, 1.0f, 0.5f, 0.0f);
	delete mapLoad;
}

Map::~Map()
{
	
}

void Map::Control()
{

}

void Map::Draw()
{
	for (unsigned int row = 0; row < m_csvData.size(); row++)
	{
		std::vector<std::string> rec = m_csvData[row];
		for (unsigned int col = 0; col < rec.size(); col++)
		{
			if (m_csvData[row][col] == "1")
			{
				m_rLibrary.DrawLeftTop(ResourceManager::MainTex::MAP_CHIP, NORMAL_BLOCK, (col * m_kBlockWidth), (row * m_kBlockHeight));
			}
		}
		
	}
}