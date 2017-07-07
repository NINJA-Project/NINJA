/**
 * @file	Font.cpp
 * @breif	フォントの設定・描画するクラス実装
 * @author	shibata
 */

#include "Font.h"
#include "GraphicsDevice.h"
#include "CommoSystem.h"

Font::Font() : 
m_pFont(nullptr),
m_pGraphicsDevice(GraphicsDevice::GetInstance().GetDevice())
{
	if (FAILED(D3DXCreateFont(
		m_pGraphicsDevice,
		20,
		10,
		FW_REGULAR,
		NULL,
		FALSE,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		PROOF_QUALITY,
		FIXED_PITCH | FF_MODERN,
		TEXT("ＭＳ　Ｐゴシック"),
		&m_pFont)))
	{
		MyAssert(m_pFont, "Fontの初期化に失敗しました");
	}
}

Font::Font(int width_, int height_) : 
m_pFont(nullptr),
m_pGraphicsDevice(GraphicsDevice::GetInstance().GetDevice())
{
	if (FAILED(D3DXCreateFont(
		m_pGraphicsDevice,
		height_,
		width_,
		FW_REGULAR,
		NULL,
		FALSE,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		PROOF_QUALITY,
		FIXED_PITCH | FF_MODERN,
		TEXT("ＭＳ　Ｐゴシック"),
		&m_pFont)))
	{
		MyAssert(m_pFont, "Fontの初期化に失敗しました");
	}
}

Font::~Font()
{
	SafeRelease(m_pFont);
}

void Font::DrawFont(const char* pString_, const Vector2D& position_, DWORD format_, int red_, int green_, int blue_)
{
	RECT rect;
	{
		D3DXFONT_DESC desc;
		m_pFont->GetDesc(&desc);

		rect.left = (LONG)position_.x;
		rect.top = (LONG)position_.y;
		rect.right = (LONG)position_.x + desc.Width * strlen(pString_);
		rect.bottom = (LONG)position_.y + desc.Height * strlen(pString_);
	}

	m_pFont->DrawText(
		NULL,
		pString_,
		-1,
		&rect,
		format_,
		D3DCOLOR_XRGB(red_, green_, blue_)
		);
}