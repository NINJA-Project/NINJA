/**
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

void Vertices::SetTexSize(float width_, float height_, const fRect& UV_, float depth_)
{
	m_texWidth  = width_;
	m_texHeight = height_;
	m_texMaxTu  = UV_.rightTop;
	m_texMaxTv  = UV_.rightBottom;
	m_texMinTu  = UV_.leftTop;
	m_texMinTv  = UV_.leftBottom;
	m_texDepth	= depth_;
}

void Vertices::DrawLeftTop(const Vector2D& position_, const LPDIRECT3DTEXTURE9& pTextureData_)
{
	CUSTOMVERTEX vertex[4] =
	{
		{ Vector3D(0.0f, 0.0f, m_texDepth),				 1.0f, m_colors[0], Vector2D(m_texMinTu, m_texMinTv) },
		{ Vector3D(m_texWidth, 0.0f, m_texDepth),		 1.0f, m_colors[1], Vector2D(m_texMaxTu, m_texMinTv) },
		{ Vector3D(m_texWidth, m_texHeight, m_texDepth), 1.0f, m_colors[2], Vector2D(m_texMaxTu, m_texMaxTv) },
		{ Vector3D(0.0f, m_texHeight, m_texDepth),		 1.0f, m_colors[3], Vector2D(m_texMinTu, m_texMaxTv) },
	};

	for (int i = 0; i < 4; i++)
	{
		vertex[i].position.x += position_.x;
		vertex[i].position.y += position_.y;
	}

	m_pGraphicsDevice->SetTexture(0, pTextureData_);
	m_pGraphicsDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));
}

void Vertices::DrawCenter(const Vector2D& position_, const LPDIRECT3DTEXTURE9& pTextureData_)
{
	CUSTOMVERTEX vertex[4] =
	{
		{ Vector3D(-m_texWidth / 2.0f, -m_texHeight / 2.0f, m_texDepth), 1.0f, m_colors[0], Vector2D(m_texMinTu, m_texMinTv) },
		{ Vector3D(m_texWidth / 2.0f, -m_texHeight / 2.0f, m_texDepth),  1.0f, m_colors[1], Vector2D(m_texMaxTu, m_texMinTv) },
		{ Vector3D(m_texWidth / 2.0f,  m_texHeight / 2.0f, m_texDepth),  1.0f, m_colors[2], Vector2D(m_texMaxTu, m_texMaxTv) },
		{ Vector3D(-m_texWidth / 2.0f,  m_texHeight / 2.0f, m_texDepth), 1.0f, m_colors[3], Vector2D(m_texMinTu, m_texMaxTv) },
	};

	for (int i = 0; i < 4; i++)
	{
		vertex[i].position.x += position_.x;
		vertex[i].position.y += position_.y;
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

void Vertices::SetUV(const fRect& currentUV_)
{
	m_texMaxTu = currentUV_.rightTop;
	m_texMaxTv = currentUV_.rightBottom;
	m_texMinTu = currentUV_.leftTop;
	m_texMinTv = currentUV_.rightBottom;
}
