/**
 * @file	Light.h
 * @breif	ライトの設定をするクラスヘッダ
 * @author	shibata
 */

#ifndef LIGHT_H
#define LIGHT_H

#include <d3dx9.h>

class Light
{
public:
	/**コンストラクタ*/
	Light();

	/**
	 * @param [in] direction_ ワールド空間での光の指す方向
	 * @note direction_のデフォルト値は(0.0f, 0.0f, 1.0f)
	 * @attention direction_は0.0fより大きな値を入れなければならない	
	 */
	Light(const D3DXVECTOR3& direction_);
	/**デストラクタ*/
	~Light();

	/**
	 * ライトの設定をする関数
	 * @param [in] ambientLight_	アンビエント光の強さ(光の強さ)
	 * @note ambientLight_のデフォルト値は0x00000000
	 */
	void Lighting(const DWORD& ambientLight_ = 0x0000000000);

private:
	D3DLIGHT9				m_light;			//!< ライト設定をする構造体
	LPDIRECT3DDEVICE9		m_pGraphicsdevice;	//!< DirectX9から取ってきたデバイス
};

#endif // !LIGHT_H