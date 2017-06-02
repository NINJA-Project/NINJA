/**
 * @file	Camera.h
 * @breif	カメラの設定をするクラスヘッダ
 * @author	shibata
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <d3dx9.h>

class Window;

class Camera
{
public:
	/**コンストラクタ*/
	Camera();
	/**デストラクタ*/
	~Camera();

	/**
	* ウィンドウサイズを伝える関数
	* @param [in] width_	ウィンドウの幅
	* @param [in] height_	ウィンドウの高さ
	*/
	void InputWindowSize(int width_, int height_);

	/**
	* カメラ座標と射影を設定する関数
	* @param [in]	index_			配置するカメラID
	* @param [in]	eyePoint_		カメラの角度(レンズ)が正面を向いてる状態でのカメラの位置
	* @param [in]	lookAtPoint_	カメラの位置を元にレンズの角度を決めるベクトル(方向)
	* @param [in]	angle_			画角の広さ
	* @param [in]	nearZ_			カメラが移せる一番近い描画位置
	* @param [in]	farZ_			カメラが移せる一番遠い描画位置
	* @note nearZ_のデフォルト値は1.0f
	* @note farZ_のデフォルト値は10000.0f
	* @note angle_のデフォルト値は50.0f
	*/
	void TransformView(const D3DXVECTOR3& eyePoint_, const D3DXVECTOR3& lookAtPoint_, float angle_ = 50.0f, float nearZ_ = 1.0f, float farZ_ = 10000.0f);

private:
	LPDIRECT3DDEVICE9	m_pGraphicsDevice;	//!< DirectX9から取ってきたデバイス
	int					m_winWidth;
	int					m_winHeight;
};


#endif // !CAMERA_H