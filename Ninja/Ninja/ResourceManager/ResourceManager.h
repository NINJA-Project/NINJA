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
		MAP_CHIP1,
		MAP_CHIP2,
		MAP_CHIP3,
		Player_Standing1,		//プレイヤー立ち絵
		Player_Standeing2,		//プレイヤー立ち絵2
		Player_Run1,			//プレイヤー走り
		Player_Run2,			//プレイヤー走り2
		Player_Run3,			//プレイヤー走り3

	};
#pragma endregion
#pragma region マップチップID
	enum ChipID
	{
		NONE,			// なにもなし
		NORMAL_BLOCK,	// 通常のブロック
		LANDING_BLOCK,	// 乗り場ブロック
		LANDING_BLOCK2,	// 仮の名前
	};
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