/**
 * @file	ResourceManager.h
 * @breif	ゲーム上で必要なリソース読み込みクラスヘッダ
 * @author	shibata
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <Library\Singleton.h>
#include "../Scene/Scene.h"

class Library;

class ResourceManager : public Singleton<ResourceManager>
{
private:
	friend Singleton<ResourceManager>;
	ResourceManager();
	virtual ~ResourceManager();

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
	};
#pragma endregion

public:
	void TexLoader(Scene::ID currentID_);
	void CSVLoader();

private:
	Library&	m_rLibrary;
};

#endif // !RESOURCEMANAGER_H