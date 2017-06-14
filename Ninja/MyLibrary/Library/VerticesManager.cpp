/**
 * @file	VerticesManager.cpp
 * @breif	頂点情報を管理しているクラス実装
 * @author	shibata
 */

#include "VerticesManager.h"
#include "Vertices.h"
#include "DebugSystem.h"

VerticesManager::VerticesManager()
{

}

VerticesManager::~VerticesManager()
{
	ReleaseAllVirtices();
}

void VerticesManager::SetTexSize(int loadIndex_, int drawIndex_, float width_, float height_, float maxTu_, float maxTv_, float minTu_, float minTv_, float depth_)
{
	m_pVertices.emplace_back(New Vertices);
	m_pVertices[loadIndex_][drawIndex_]->SetTexSize(width_, height_, maxTu_, maxTv_, minTu_, minTv_, depth_);
}

void VerticesManager::DrawLeftTop(int loadIndex_, int drawIndex_, float posX_, float posY_, const LPDIRECT3DTEXTURE9 pTextureData_)
{
	m_pVertices[loadIndex_][drawIndex_]->DrawLeftTop({ posX_, posY_ }, pTextureData_);
}

void VerticesManager::DrawCenter(int loadIndex_, int drawIndex_, float posX_, float posY_, const LPDIRECT3DTEXTURE9 pTextureData_)
{
	m_pVertices[loadIndex_][drawIndex_]->DrawCenter({ posX_, posY_ }, pTextureData_);
}

void VerticesManager::SetColor(int loadIndex_, int drawIndex_, DWORD color_, int alpha_, int red_, int green_, int blue_)
{
	m_pVertices[loadIndex_][drawIndex_]->SetColor(color_, alpha_, red_, green_, blue_);
}

void VerticesManager::ReleaseAllVirtices()
{
	for (unsigned int i = 0; i < m_pVertices.size(); i++)
	{
		for (unsigned int j = 0; j < m_pVertices.size(); j++)
		{
			delete m_pVertices[i][j];
		}
	}
	m_pVertices.clear();
	m_pVertices.shrink_to_fit();
}

void VerticesManager::ReleaseVirtices(int loadIndex_, int drawIndex_)
{
	if (m_pVertices[loadIndex_][drawIndex_] != NULL)
	{
		delete m_pVertices[loadIndex_][drawIndex_];
		m_pVertices[loadIndex_][drawIndex_] = NULL;
	}
}