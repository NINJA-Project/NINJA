/**
 * @file	Button.cpp
 * @breif	ボタン関係のクラス実装
 * @author	shibata
 */

#include "Button.h"
#include <Library.h>

Button::Button(float posX_, float posY_, int texindex_) :
m_rLibrary(Library::Instance()),
m_width(64.0f),
m_height(64.0f),
m_posX(posX_),
m_posY(posY_),
m_texIndex(texindex_)
{
	m_rLibrary.LoadTextureFile(m_texIndex, "Resource/Texture/Button.png");
	m_rLibrary.SetTexSize(m_texIndex, m_width, m_height);
}

Button::~Button()
{
}

bool Button::IsPush()
{
	if (m_rLibrary.CheckKey(DIK_A) == PUSH)
	{
		return true;
	}

	return false;
}

void Button::Draw()
{
	m_rLibrary.DrawCenter(m_texIndex, m_posX, m_posY);
}
