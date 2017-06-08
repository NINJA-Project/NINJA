/**
 * @file	ResourceManager.h
 * @breif	ゲーム上で必要なリソース読み込みクラスヘッダ
 * @author	shibata
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "../Scene/Scene.h"

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
	void CSVLoader();

private:
	Library&	m_rLibrary;
	const int	m_kCsvWidth;		// csvの幅
	const int	m_kCsvHeight;		// csvの高さ
};

#endif // !RESOURCEMANAGER_H