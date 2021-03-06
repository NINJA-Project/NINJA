﻿/**
 * @file	Vertices.cpp
 * @breif	頂点情報を決めるクラスヘッダ
 * @author	shibata
 */

#include "Vertices.h"
#include "GraphicsDevice.h"

Vertices::Vertices() :
m_pGraphicsDevice(GraphicsDevice::GetInstance().GetDevice()),
m_texWidth(NULL),
m_texHeight(NULL),
m_texDepth(NULL),
m_texMaxTu(NULL),
m_texMaxTv(NULL),
m_texMinTu(NULL),
m_texMinTv(NULL)
{
	for (int i = 0; i < 4; i++)
	{
		m_colors[i] = 0xffffffff;
	}
}

Vertices::~Vertices()
{

}

void Vertices::SetTexSize(float width_, float height_, float maxTu_, float maxTv_, float minTu_, float minTv_, float depth_)
{
	m_texWidth  = width_;
	m_texHeight = height_;
	m_texMaxTu  = maxTu_;
	m_texMaxTv  = maxTv_;
	m_texMinTu  = minTu_;
	m_texMinTv  = minTv_;
	m_texDepth	= depth_;
}

void Vertices::DrawLeftTop(const Vector2D& position_, const LPDIRECT3DTEXTURE9& pTextureData_)
{
	CUSTOMVERTEX vertex[4] =
	{
		{		 0.0f,		  0.0f, m_texDepth, 1.0f, m_colors[0], m_texMinTu, m_texMinTv },
		{  m_texWidth,		  0.0f, m_texDepth, 1.0f, m_colors[1], m_texMaxTu, m_texMinTv },
		{  m_texWidth, m_texHeight, m_texDepth, 1.0f, m_colors[2], m_texMaxTu, m_texMaxTv },
		{		 0.0f, m_texHeight, m_texDepth, 1.0f, m_colors[3], m_texMinTu, m_texMaxTv },
	};

	for (int i = 0; i < 4; i++)
	{
		vertex[i].x += position_.x;
		vertex[i].y += position_.y;
	}

	m_pGraphicsDevice->SetTexture(0, pTextureData_);
	m_pGraphicsDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));
}

void Vertices::DrawCenter(const Vector2D& position_, const LPDIRECT3DTEXTURE9& pTextureData_)
{
	CUSTOMVERTEX vertex[4] =
	{
		{ -m_texWidth / 2.0f, -m_texHeight / 2.0f, m_texDepth, 1.0f, m_colors[0], m_texMinTu, m_texMinTv },
		{  m_texWidth / 2.0f, -m_texHeight / 2.0f, m_texDepth, 1.0f, m_colors[1], m_texMaxTu, m_texMinTv },
		{  m_texWidth / 2.0f,  m_texHeight / 2.0f, m_texDepth, 1.0f, m_colors[2], m_texMaxTu, m_texMaxTv },
		{ -m_texWidth / 2.0f,  m_texHeight / 2.0f, m_texDepth, 1.0f, m_colors[3], m_texMinTu, m_texMaxTv },
	};

	for (int i = 0; i < 4; i++)
	{
		vertex[i].x += position_.x;
		vertex[i].y += position_.y;
	}

	m_pGraphicsDevice->SetTexture(0, pTextureData_);
	m_pGraphicsDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));

}

void Vertices::SetColor(DWORD& afterColor_, const RGBAColor& setColor_)
{
	{
		DWORD preColor = D3DCOLOR_ARGB(setColor_.a, setColor_.r, setColor_.g, setColor_.b);

		afterColor_ = preColor;
	}

	for (int i = 0; i < 4; i++)
	{
		m_colors[i] = afterColor_;
	}
}