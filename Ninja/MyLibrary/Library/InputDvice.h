/**
 * @file	InputDevice.h
 * @breif	入力機器の初期化クラスヘッダ
 * @author	shibata
 */

#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

#define DIRECTINPUT_VERSION 0x0800

#pragma region デバイスの種類
#define KEY
#define MOUSE
#define MAMEPAD
#pragma endregion


#include <dinput.h>
#include "Singleton.h"

class InputDevice : public Singleton<InputDevice>
{
private:
	friend Singleton<InputDevice>;
	/**コンストラクタ*/
	InputDevice();
	/**デストラクタ*/
	~InputDevice();

public:
	/**初期化関数*/
	void Initialize(HWND hwnd_);

	/**
	* キーボードデバイスの取得関数
	* @return m_pKeyDevice キーボードデバイス
	*/
	LPDIRECTINPUTDEVICE8 GetKeyDevice() const
	{
		return m_pKeyDevice;
	}
private:
#pragma region 各デバイスの初期化
	/**
	* キーボードデバイスの生成関数
	* @param [in]	hwnd_	ウィンドウハンドル
	*/
	void InitializeKeyDevice(HWND hwnd_);

	/**
	* マウスデバイスの生成関数
	* @param [in]	hwnd_	ウィンドウハンドル
	*/

	void InitializeMouseDevice(HWND hwnd_);
#pragma endregion


#pragma region メンバ変数
private:
	LPDIRECTINPUT8			m_pDinput;		//!< DirectInputのインターフェイス
	LPDIRECTINPUTDEVICE8	m_pKeyDevice;	//!< DirectInputのキーボード用デバイス
#pragma endregion
};

#endif // !INPUTDEVICE_H