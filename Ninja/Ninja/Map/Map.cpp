/**
 * @file	Map.cpp
 * @breif	マップクラス実装
 * @author	shibata
 */

#include "Map.h"
#include <stdio.h>
#include <Library\DebugSystem.h>
#include <Library.h>
#include "../ObjectManager/ObjectManager.h"

Map::Map() : 
m_rLibrary(Library::Instance()),
m_mapWidth(15),
m_mapHeight(20),
m_blockWidth(64.0f),
m_blockHeight(64.0f)
{
	m_rLibrary.LoadTextureFile(ObjectManager::TexID::MAP_CHIP1, "Resource/Texture/MapChip.png");
	m_rLibrary.SetTexSize(ObjectManager::TexID::MAP_CHIP1, m_blockWidth, m_blockHeight, 0.5f, 0.2f, 0.2f, 0.2f, 0.2f);
	m_rLibrary.SetTexSize(ObjectManager::TexID::MAP_CHIP2, m_blockWidth, m_blockHeight, 0.5f, 0.2f, 0.2f, 0.2f, 0.2f);
	m_rLibrary.SetTexSize(ObjectManager::TexID::MAP_CHIP3, m_blockWidth, m_blockHeight, 0.5f, 0.2f, 0.2f, 0.2f, 0.2f);

	LoadCSV("Resource/File/NinjaMap.csv");
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

void Map::LoadCSV(const char* filePath_)
{
	FILE* fp;
	fp = fopen(filePath_, "r");
	MyAssert(fp, "データが入っていません");



	fclose(fp);
}