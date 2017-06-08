/**
 * @file	ResourceManager.cpp
 * @breif	ゲーム上で必要なリソース読み込みクラス実装
 * @author	shibata
 */


#include "ResourceManager.h"
#include "../Scene/Scene.h"
#include <Library.h>
#include <stdio.h>

namespace
{
	int g_csvMap[15][20];
}

ResourceManager::ResourceManager() :
m_rLibrary(Library::Instance()),
m_kCsvWidth(15),
m_kCsvHeight(20)
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
		break;
	}
}

void ResourceManager::CSVLoader()
{
	FILE* fp;
	fopen_s(&fp, "Resource/File/NinjaMap.csv", "r");
	MyAssert(fp, "データが入っていません");

	/*
	エネミーやゴールポイント配置時に使用する
	for (int i = 0; i < m_kCsvHeight; i++)
	{
		for (int j = 0; j < m_kCsvWidth; j++)
		{
			fscanf_s(fp, "%d,", g_csvMap[i][j],sizeof(int));
			switch (g_csvMap[i][j])
			{

			}
		}
	}
	*/

	fclose(fp);
}
