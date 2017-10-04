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

void VertexManager::SetTexSize(int index_, float width_, float height_, const fRect& UV_, float depth_)
{
	m_pVertices.emplace_back(New Vertices);
	m_pVertices[index_]->SetTexSize(width_, height_, UV_, depth_);
}

void VertexManager::DrawLeftTop(int index_, float posX_, float posY_, const LPDIRECT3DTEXTURE9& pTextureData_)
{
	m_pVertices[index_]->DrawLeftTop({ posX_, posY_ }, pTextureData_);
}

void VertexManager::DrawCenter(int index_, float posX_, float posY_, const LPDIRECT3DTEXTURE9& pTextureData_)
{
	m_pVertices[index_]->DrawCenter({ posX_, posY_ }, pTextureData_);
}

void VertexManager::SetColor(int index_, DWORD& afterColor_, int alpha_, int red_, int green_, int blue_)
{
	m_pVertices[index_]->SetColor(afterColor_, RGBAColor(alpha_, red_, green_, blue_));
}

void VertexManager::SetUV(int index_, const fRect& currentUV_)
{
	m_pVertices[index_]->SetUV(currentUV_);
}

void VertexManager::ReleaseAllVirtices()
{
	// @todo itrの変数名を後々変更する
	for (auto& itr : m_pVertices)
	{
		delete itr;
	}
}

void VertexManager::ReleaseVirtices(int index_)
{
	if (m_pVertices[index_] != NULL)
	{
		delete m_pVertices[index_];
		m_pVertices[index_] = NULL;
	}
}