/**
 * @file	ResourceManager.h
 * @breif	ゲーム上で必要なリソース読み込みクラスヘッダ
 * @author	shibata
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "../Scene/Scene.h"
#include <vector>
#include <string>

class Library;

class ResourceManager
{
public:
#pragma region ロゴシーンのテクスチャID
	enum LogoTex
	{
		LOGO
	};
#pragma endregion
#pragma region タイトルシーンのテクスチャID
	enum TitleTex
	{
		TITLE_LOGO,
		BUTTON,
		START_LOGO,
		HOWTOPLAY_LOGO
	};
#pragma endregion
#pragma region メインシーンのテクスチャID
	enum MainTex
	{
		MAP_CHIP,
		PLAYER,					//プレイヤー
	};
#pragma endregion
#pragma region マップチップID

#pragma endregion


public:
	ResourceManager();
	~ResourceManager();

	void TexLoader(Scene::ID currentID_);
	bool CSVLoader(std::vector<std::vector<std::string>>& data_, const char delim_ = ',');

private:
	Library&			m_rLibrary;
};

#endif // !RESOURCEMANAGER_H