/**
 * @file	GraphicsDevice.cpp
 * @breif	DirectXの初期化クラス実装
 * @author	shibata
 */

#include "GraphicsDevice.h"
#include "CommoSystem.h"
#include "Directives.h"

GraphicsDevice::GraphicsDevice() :
m_pDirect3D(nullptr),
m_pD3Device(nullptr)
{

}

GraphicsDevice::~GraphicsDevice()
{
	SafeRelease(m_pD3Device);
	SafeRelease(m_pDirect3D);
}

void GraphicsDevice::Initialize(HWND hwnd_, int clientWidth_, int clientHeight_)
{
	m_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);
	MyAssert(m_pDirect3D, "初期化に失敗しました");

	// ウィンドウタイプの設定
	{
		// ディスプレイモード
		D3DDISPLAYMODE d3ddm;
		m_pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);

		// 最終的なウィンドウパラメーター
		D3DPRESENT_PARAMETERS d3dpp;
		ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));

#ifdef FULL_SCREEN
		// フルスクリーンパラメーター
		D3DPRESENT_PARAMETERS fullScreenPrm;
		ZeroMemory(&fullScreenPrm, sizeof(D3DPRESENT_PARAMETERS));
		fullScreenPrm.BackBufferWidth			= clientWidth_;
		fullScreenPrm.BackBufferHeight			= clientHeight_;
		fullScreenPrm.BackBufferFormat			= d3ddm.Format;
		fullScreenPrm.BackBufferCount			= 1;
		fullScreenPrm.SwapEffect				= D3DSWAPEFFECT_DISCARD;
		fullScreenPrm.hDeviceWindow				= hwnd_;
		fullScreenPrm.Windowed					= FALSE;
		fullScreenPrm.PresentationInterval		= D3DPRESENT_INTERVAL_DEFAULT;
		d3dpp									= fullScreenPrm;
#elif defined(WINDOW_SCREEN)
		// ウィンドウスクリーンパラメーター
		D3DPRESENT_PARAMETERS windowScreenPrm;
		ZeroMemory(&windowScreenPrm, sizeof(D3DPRESENT_PARAMETERS));
		windowScreenPrm.BackBufferFormat	= d3ddm.Format;
		windowScreenPrm.BackBufferCount		= 1;
		windowScreenPrm.SwapEffect			= D3DSWAPEFFECT_DISCARD;
		windowScreenPrm.Windowed			= TRUE;
		d3dpp								= windowScreenPrm;
#endif
		m_pDirect3D->CreateDevice(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hwnd_,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp,
			&m_pD3Device);
		MyAssert(m_pD3Device, "初期化に失敗しました");
	}

#ifdef THREE
	Initialize3DRendering();
#elif defined(TWO)
	InitializeRendering();
#endif 	
}

void GraphicsDevice::SetFVF(DWORD fvf_)
{
	m_pD3Device->SetFVF(fvf_);
}

void GraphicsDevice::RenderStarting()
{
	m_pD3Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);

	m_pD3Device->BeginScene();
}

void GraphicsDevice::RenderEnding()
{
	m_pD3Device->EndScene();

	m_pD3Device->Present(NULL, NULL, NULL, NULL);
}

#pragma region privateメンバ関数
void GraphicsDevice::InitializeRendering()
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

void GraphicsDevice::Initialize3DRendering()
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

	m_pD3Device->SetRenderState(D3DRS_ZENABLE, TRUE);			// Zバッファー処理を有効に(3D)
	m_pD3Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);	// カリングする
}
#pragma endregion