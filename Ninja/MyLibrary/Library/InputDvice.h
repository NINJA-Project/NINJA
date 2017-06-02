/**
 * @file	InputDevice.h
 * @breif	入力機器の初期化クラスヘッダ
 * @author	shibata
 */

#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include "Singleton.h"

class InputDevice : public Singleton<InputDevice>
{
private:
	friend Singleton<InputDevice>;
	/**コンストラクタ*/
	InputDevice();
	/**デストラクタ*/
	virtual ~InputDevice();

public:
	/**
	 * DirectInputの初期化関数
	 * @retval true		初期化成功
	 * @retval false	初期化失敗
	 */
	bool InitInput();

	/**
	 * キーボードデバイスの生成関数
	 * @param [in]	hWnd_	ウィンドウハンドル
	 * @retval		true	生成成功
	 * @retval		false	生成失敗
	 */
	bool InitInputKey(HWND hWnd_);

	/**
	 * キーボードデバイスの取得関数
	 * @return m_pKeyDevice キーボードデバイス
	 */
	LPDIRECTINPUTDEVICE8 GetKeyDevice()
	{
		return m_pKeyDevice;
	}

private:
	LPDIRECTINPUT8			m_pDinput;		//!< DirectInputのインターフェイス
	LPDIRECTINPUTDEVICE8	m_pKeyDevice;	//!< DirectInputのキーボード用デバイス
};

#endif // !INPUTDEVICE_H