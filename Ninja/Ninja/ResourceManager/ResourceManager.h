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
		Player_Standing1,		//プレイヤー立ち絵
		Player_Standeing2,		//プレイヤー立ち絵2
		Player_Run1,			//プレイヤー走り
		Player_Run2,			//プレイヤー走り2
		Player_Run3,			//プレイヤー走り3
	};
#pragma endregion

public:
	void TexLoader(Scene::ID currentID_);
	void CSVLoader();

private:
	Library&	m_rLibrary;
};

#endif // !RESOURCEMANAGER_H