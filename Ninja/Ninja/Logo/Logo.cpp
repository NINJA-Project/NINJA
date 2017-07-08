/**
 * @file	Logo.cpp
 * @breif	ロゴ系を表示するクラス実装
 * @author	shibata
 */

#include "Logo.h"
#include <Library.h>

/// @TODO 後に、クラスの仕様変更をする

Logo::Logo(float width_, float height_, float posX_, float posY_, int texindex_, const char* pFilePath_) :
m_rLibrary(Library::GetInstance()),
m_posX(posX_),
m_posY(posY_),
m_width(width_),
m_height(height_),
m_texindex(texindex_),
m_pFilePath(pFilePath_)
{
	m_rLibrary.LoadTexture(m_texindex, m_pFilePath);
//	m_rLibrary.SetTexSize(m_texindex, m_width, m_height);
}

Logo::~Logo()
{
}

void Logo::Draw()
{
//	m_rLibrary.DrawCenter(m_texindex, m_posX, m_posY);
}
