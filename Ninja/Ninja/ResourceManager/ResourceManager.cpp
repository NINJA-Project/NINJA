/**
 * @file	ResourceManager.cpp
 * @breif	ゲーム上で必要なリソース読み込みクラス実装
 * @author	shibata
 */


#include "ResourceManager.h"
#include "../Scene/Scene.h"
#include <Library.h>
#include <fstream>
#include <iostream>
#include <sstream>

ResourceManager::ResourceManager() :
m_rLibrary(Library::Instance())
{

}

ResourceManager::~ResourceManager()
{

}

void ResourceManager::TexLoader(Scene::ID currentID_)
{
	switch (currentID_)
	{
	case Scene::ID::LOGO_SCENE:
		// ここに読み込むテクスチャを書く
		// 新規で読み込む際はhの対応するenumにテクスチャIDを追加すること
		break;
	case Scene::ID::TITLE_SCENE:
		// ここに読み込むテクスチャを書く
		// 新規で読み込む際はhの対応するenumにテクスチャIDを追加すること

		break;
	case Scene::ID::MAIN_SCENE:
		// ここに読み込むテクスチャを書く
		// 新規で読み込む際はhの対応するenumにテクスチャIDを追加すること
		m_rLibrary.LoadTextureFile(MAP_CHIP, "Resource/Texture/MapChip.png");
		m_rLibrary.LoadTextureFile(ResourceManager::MainTex::Player_Standing1, "Resource/Texture/Player_Standing1.png");
		break;
	}
}

bool ResourceManager::CSVLoader(std::vector<std::vector<std::string>>& data_, const char delim_)
{
	std::ifstream csvFile("Resource/File/NinjaMap.csv");
	MyAssert(csvFile, "データが入っていません");

	std::string buf;

	while (getline(csvFile, buf))
	{
		std::vector<std::string> rec;
		std::istringstream iss(buf);
		std::string field;

		while (getline(iss, field, delim_))
		{
			rec.push_back(field);
		}

		if (rec.size() != 0)
		{
			data_.push_back(rec);
		}
	}

	return true;
}