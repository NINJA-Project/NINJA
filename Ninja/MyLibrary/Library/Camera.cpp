/**
 * @file	Camera.cpp
 * @breif	カメラの設定をするクラス実装
 * @author	shibata
 */

#include "Camera.h"
#include "DirectX9.h"

Camera::Camera() : 
m_pGraphicsDevice(DirectX9::Instance().GetDevice()),
m_winWidth(0),
m_winHeight(0)
{

}

Camera::~Camera()
{

}

void Camera::InputWindowSize(int width_, int height_)
{
	m_winWidth	= width_;
	m_winHeight = height_;
}

void Camera::TransformView(const D3DXVECTOR3& eyePoint_, const D3DXVECTOR3& lookAtPoint_, float angle_, float nearZ_, float farZ_)
{
	{
		D3DXMATRIXA16 matView;
		D3DXVECTOR3 vecUpVec(0.0f, 1.0f, 0.0f);	//カメラの上下の向きを決める

		D3DXMatrixLookAtLH(&matView, &eyePoint_, &lookAtPoint_, &vecUpVec);
		m_pGraphicsDevice->SetTransform(D3DTS_VIEW, &matView);
	}

	{
		// プロジェクショントランスフォーム（射影変換）
		D3DXMATRIXA16 matProj;

		D3DXMatrixIdentity(&matProj);

		float viewAngle = D3DXToRadian(angle_);
		float aspect = static_cast<float>(m_winWidth / m_winHeight);
		float nearZ = nearZ_;
		float farZ = farZ_;

		D3DXMatrixPerspectiveFovLH(&matProj, viewAngle, aspect, nearZ, farZ);
		m_pGraphicsDevice->SetTransform(D3DTS_PROJECTION, &matProj);
	}
}
