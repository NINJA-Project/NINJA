/**
 * @file	VertexManager.cpp
 * @breif	頂点情報を管理しているクラス実装
 * @author	shibata
 */

#include "VertexManager.h"
#include "Vertices.h"
#include "CommoSystem.h"

VertexManager::VertexManager()
{

}

VertexManager::~VertexManager()
{
	ReleaseAllVirtices();
}

void VertexManager::SetTexSize(int loadIndex_, int drawIndex_, float width_, float height_, float maxTu_, float maxTv_, float minTu_, float minTv_, float depth_)
{
	// todo　m_pLoadTexが1つの画像に対し2回呼ばれているため配列外アクセスが発生している
	m_pLoadTex.emplace_back(New Vertices);
	m_pDrawTex.emplace_back(New Vertices);
	m_pVertices.emplace_back(m_pLoadTex);
	m_pVertices.emplace_back(m_pDrawTex);
	m_pVertices[loadIndex_][drawIndex_]->SetTexSize(width_, height_, maxTu_, maxTv_, minTu_, minTv_, depth_);
}

void VertexManager::DrawLeftTop(int loadIndex_, int drawIndex_, float posX_, float posY_, const LPDIRECT3DTEXTURE9 pTextureData_)
{
	m_pVertices[loadIndex_][drawIndex_]->DrawLeftTop({ posX_, posY_ }, pTextureData_);
}

void VertexManager::DrawCenter(int loadIndex_, int drawIndex_, float posX_, float posY_, const LPDIRECT3DTEXTURE9 pTextureData_)
{
	m_pVertices[loadIndex_][drawIndex_]->DrawCenter({ posX_, posY_ }, pTextureData_);
}

void VertexManager::SetColor(int loadIndex_, int drawIndex_, DWORD color_, int alpha_, int red_, int green_, int blue_)
{
	m_pVertices[loadIndex_][drawIndex_]->SetColor(color_, alpha_, red_, green_, blue_);
}

void VertexManager::ReleaseAllVirtices()
{
	for (unsigned int i = 0; i < m_pLoadTex.size(); i++)
	{
		for (unsigned int j = 0; j < m_pDrawTex.size(); j++)
		{
			delete m_pVertices[i][j];
		}
	}
	m_pDrawTex.clear();
	m_pDrawTex.shrink_to_fit();
	m_pLoadTex.clear();
	m_pLoadTex.shrink_to_fit();
	m_pVertices.clear();
	m_pVertices.shrink_to_fit();
}

void VertexManager::ReleaseVirtices(int loadIndex_, int drawIndex_)
{
	if (m_pVertices[loadIndex_][drawIndex_] != NULL)
	{
		delete m_pVertices[loadIndex_][drawIndex_];
		m_pVertices[loadIndex_][drawIndex_] = NULL;
	}
}