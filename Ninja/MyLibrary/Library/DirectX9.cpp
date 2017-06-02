/**
 * @file	DirectX9.cpp
 * @breif	DirectXの初期化クラス実装
 * @author	shibata
 */

#include "DirectX9.h"
#include "Define.h"

DirectX9::DirectX9() :
m_pDirect3D(NULL),
m_pD3Device(NULL)
{

}

DirectX9::~DirectX9()
{
	SafeRelease(m_pD3Device);
	SafeRelease(m_pDirect3D);
}

bool DirectX9::InitDirectX(HWND hWnd_, int clientWidth_, int clientHeight_, bool isFullScreen_)
{
	m_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (m_pDirect3D == NULL)
	{
		MessageBox(NULL, "インターフェイスが生成できませんでした。", NULL, MB_OK);
		return false;
	}

	// ウィンドウタイプの設定
	{
		// ディスプレイモード
		D3DDISPLAYMODE m_d3ddm;

		m_pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &m_d3ddm);

		// フルスクリーンパラメーター
		D3DPRESENT_PARAMETERS fullScreenPrm;
		ZeroMemory(&fullScreenPrm, sizeof(D3DPRESENT_PARAMETERS));
		fullScreenPrm.BackBufferWidth      = clientWidth_;
		fullScreenPrm.BackBufferHeight     = clientHeight_;
		fullScreenPrm.BackBufferFormat     = m_d3ddm.Format;
		fullScreenPrm.BackBufferCount      = 1;
		fullScreenPrm.SwapEffect           = D3DSWAPEFFECT_DISCARD;
		fullScreenPrm.hDeviceWindow        = hWnd_;
		fullScreenPrm.Windowed             = FALSE;
		fullScreenPrm.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;

		// ウィンドウスクリーンパラメーター
		D3DPRESENT_PARAMETERS windowScreenPrm;
		ZeroMemory(&windowScreenPrm, sizeof(D3DPRESENT_PARAMETERS));
		windowScreenPrm.BackBufferFormat = m_d3ddm.Format;
		windowScreenPrm.BackBufferCount  = 1;
		windowScreenPrm.SwapEffect       = D3DSWAPEFFECT_DISCARD;
		windowScreenPrm.Windowed         = TRUE;

		// 最終的なウィンドウパラメーター
		D3DPRESENT_PARAMETERS d3dpp;		
		ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));
		if (isFullScreen_)
		{
			d3dpp = fullScreenPrm;
		}
		else
		{
			d3dpp = windowScreenPrm;
		}

		m_pDirect3D->CreateDevice(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hWnd_,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp,
			&m_pD3Device);
	}

	if (m_pD3Device == NULL)
	{
		MessageBox(NULL, "デバイスが生成できませんでした。", NULL, MB_OK);
		m_pDirect3D->Release();

		return false;
	}

	InitDraw();

	return true;
}

void DirectX9::SetFVF(DWORD fvf_)
{
	m_pD3Device->SetFVF(fvf_);
}

void DirectX9::DrawStart()
{
	m_pD3Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);

	m_pD3Device->BeginScene();
}

void DirectX9::DrawEnd()
{
	m_pD3Device->EndScene();

	m_pD3Device->Present(NULL, NULL, NULL, NULL);
}

void DirectX9::Init3DDraw()
{
	m_pD3Device->SetRenderState(D3DRS_ZENABLE, TRUE);			// Zバッファー処理を有効に(3D)
	m_pD3Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);	// カリングする
}

void DirectX9::InitDraw()
{
	m_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	m_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	m_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	m_pD3Device->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	m_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	m_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	m_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	m_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	m_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}