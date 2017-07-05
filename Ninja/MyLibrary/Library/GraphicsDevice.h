/**
 * @file	GraphicsDevice.h
 * @breif	DirectXの初期化クラスヘッダ
 * @author	shibata
 */

#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H

#include <d3dx9.h>
#include "Singleton.h"

class GraphicsDevice : public Singleton<GraphicsDevice>
{
private:
	friend Singleton<GraphicsDevice>;
	/**コンストラクタ*/
	GraphicsDevice();
	/**デストラクタ*/
	~GraphicsDevice();

public:
	/**
	 * 初期化関数
	 * @param [in]	hwnd_			ウィンドウハンドル
	 * @param [in]	clientWidth_	画面横幅のサイズ
	 * @param [in]	clientHeight_	画面縦幅のサイズ
	 * @param [in]	isFullScreen_	フルスクリーンかどうか		@note デフォルトはLibraryクラスで false に設定している
	 */
	void Initialize(HWND hwnd_, int clientWidth_, int clientHeight_, bool isFullScreen_);

	/**
	 * 頂点フォーマット設定関数
	 * @param [in] fvf_ 頂点フォーマットの設定			@note デフォルトはLibraryクラスで D3DFVF_CUSTOMVERTEX に設定している
	 */
	void SetFVF(DWORD fvf_);

	/**描画開始関数*/
	void RenderStarting();

	/**描画終了関数*/
	void RenderEnding();

	/**
	 * デバイス取得関数
	 * @return	m_pD3Device	デバイス情報
	 */
	LPDIRECT3DDEVICE9 GetDevice() const
	{
		return m_pD3Device;
	}

private:
#pragma region メンバ関数
	/**描画初期化関数*/
	void InitializeRendering();
	/**
	* 描画初期化関数				@note 3Dを描画するときに使用
	*/
	void Initialize3DRendering();
#pragma endregion

#pragma region メンバ変数
private:
	LPDIRECT3D9			m_pDirect3D;	//!< DirectXのインターフェイス
	LPDIRECT3DDEVICE9	m_pD3Device;	//!< DirectXのデバイス
#pragma endregion
};

#endif // !GRAPHICSDEVICE_H