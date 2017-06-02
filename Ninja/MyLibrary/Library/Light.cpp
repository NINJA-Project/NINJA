/**
 * @file	Light.cpp
 * @breif	ライトの設定をするクラス実装
 * @author	shibata
 */

#include "Light.h"
#include "DirectX9.h"

Light::Light() : 
m_pGraphicsdevice(DirectX9::Instance().GetDevice())
{
	D3DXVECTOR3 direction_ = { 0.0f, 0.0f, 1.0f };
	ZeroMemory(&m_light, sizeof(D3DLIGHT9));
	m_light.Type = D3DLIGHT_DIRECTIONAL;
	m_light.Diffuse.r = 1.0f;
	m_light.Diffuse.g = 1.0f;
	m_light.Diffuse.b = 1.0f;
	m_light.Specular.r = 1.0f;
	m_light.Specular.g = 1.0f;
	m_light.Specular.b = 1.0f;
	m_light.Direction = direction_;
	D3DXVec3Normalize((D3DXVECTOR3*)&m_light.Direction, &direction_);
	m_light.Range = 500.0f;
}

Light::Light(const D3DXVECTOR3& direction_) : 
m_pGraphicsdevice(DirectX9::Instance().GetDevice())
{
	ZeroMemory(&m_light, sizeof(D3DLIGHT9));
	m_light.Type = D3DLIGHT_DIRECTIONAL;
	m_light.Diffuse.r = 1.0f;
	m_light.Diffuse.g = 1.0f;
	m_light.Diffuse.b = 1.0f;
	m_light.Specular.r = 1.0f;
	m_light.Specular.g = 1.0f;
	m_light.Specular.b = 1.0f;
	m_light.Direction = direction_;
	D3DXVec3Normalize((D3DXVECTOR3*)&m_light.Direction, &direction_);
	m_light.Range = 500.0f;
}

Light::~Light()
{

}

void Light::Lighting(const DWORD& ambientLight_)
{
	m_pGraphicsdevice->SetLight(0, &m_light);
	m_pGraphicsdevice->LightEnable(0, TRUE);

	m_pGraphicsdevice->SetRenderState(D3DRS_LIGHTING, TRUE);			// ライトを有効に
	m_pGraphicsdevice->SetRenderState(D3DRS_AMBIENT, ambientLight_);	// アンビエントライト(環境光)を設定
	m_pGraphicsdevice->SetRenderState(D3DRS_SPECULARENABLE, TRUE);		// スペキュラ(鏡面反射)を有効に

}