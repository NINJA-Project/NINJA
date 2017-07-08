/**
 * @file	TextureFileManager.cpp
 * @breif	画像の読み込みを管理しているクラス実装
 * @author	shibata
 */

#include "TextureFileManager.h"
#include "TextureFile.h"
#include "Debug.h"

TextureFileManager::TextureFileManager()
{

}

TextureFileManager::~TextureFileManager()
{
	ReleaseAllTexture();
}

void TextureFileManager::Load(int index_, const char* filePath_)
{
	m_pTextureFile.emplace_back(New TextureFile);
	m_pTextureFile[index_]->Load(filePath_);
}

void TextureFileManager::LoadMoreInfo(int index_, const char* filePath_, int alpha_, int red_, int green_, int blue_, bool isTwoPower_)
{
	m_pTextureFile.emplace_back(New TextureFile);
	m_pTextureFile[index_]->LoadMoreInfo(filePath_, RGBAColor(red_, green_, blue_, alpha_), isTwoPower_);
}

LPDIRECT3DTEXTURE9 TextureFileManager::GetTextureFileData(int index_) const
{
	return m_pTextureFile[index_]->GetTextureFileData();
}

void TextureFileManager::ReleaseAllTexture()
{
	// @todo itrの変数名を後々変更する
	for (auto& itr : m_pTextureFile)
	{
		delete itr;
	}
}

void TextureFileManager::ReleaseTexture(int index_)
{
	if (m_pTextureFile[index_] != NULL)
	{
		delete m_pTextureFile[index_];
		m_pTextureFile[index_] = NULL;
	}
}