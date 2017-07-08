/**
 * @file	TextureFile.cpp
 * @breif	画像ファイルの読み込みクラス実装
 * @author	shibata
 */

#include "TextureFile.h"
#include "GraphicsDevice.h"
#include "CommoSystem.h"

TextureFile::TextureFile() : 
m_pTexture(NULL),
m_pGraphicsDevice(GraphicsDevice::GetInstance().GetDevice())
{

}

TextureFile::~TextureFile()
{
	SafeRelease(m_pTexture);
}

void TextureFile::Load(const char* filePath_)
{
	if (FAILED(D3DXCreateTextureFromFile(m_pGraphicsDevice, filePath_, &m_pTexture)))
	{
		MyAssert(m_pTexture, "画像が読み込めませんでした");
	}
}

void TextureFile::LoadMoreInfo(const char* filePath_, const RGBAColor& color_, bool isTwoPower_)
{
	if (isTwoPower_)	// 2の累乗なら
	{
		if (D3DXCreateTextureFromFileEx(
			m_pGraphicsDevice,
			filePath_,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			0,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_FILTER_NONE,
			D3DX_DEFAULT,
			D3DCOLOR_ARGB(color_.a, color_.r, color_.g, color_.b),
			NULL,
			NULL,
			&m_pTexture
			))
		{
			MyAssert(m_pTexture, "画像が読み込めませんでした");
		}
	}
	else			// 2の累乗でないのなら
	{
		if (FAILED(D3DXCreateTextureFromFileEx(
			m_pGraphicsDevice,
			filePath_,
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT,
			0,
			D3DFMT_UNKNOWN,
			D3DPOOL_MANAGED,
			D3DX_FILTER_NONE,
			D3DX_FILTER_NONE,
			D3DCOLOR_ARGB(color_.a, color_.r, color_.g, color_.b),
			NULL,
			NULL,
			&m_pTexture
			)))
		{
			MyAssert(m_pTexture, "画像が読み込めませんでした");
		}
	}
}