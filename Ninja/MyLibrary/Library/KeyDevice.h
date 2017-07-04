/**
 * @file	KeyDevice.h
 * @breif	キーボード関係のクラスヘッダ
 * @author	shibata
 */

#ifndef INPUTKEY_H
#define INPUTKEY_H

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>

class KeyDevice
{
#pragma region キーの状態enum
private:
	/// キーの状態
	enum State
	{
		KEY_PUSH,
		KEY_RELEASE,
		KEY_ON,
		KEY_OFF,
	};
#pragma endregion

public:
	/**コンストラクタ*/
	KeyDevice();
	/**デストラクタ*/
	~KeyDevice();

	/**キー情報の更新する関数*/
	void Update();

	/**
	 * キーの状態を決める関数
	 * @param [in]	dik_			どのキーを使うか
	 * @return		m_keyKind[dik_]	キーの状態
	 */
	State ChooseKey(int dik_);

#pragma region メンバ変数
private:
	static const int		m_kMaxKeyByte = 256;				//!< キー選択肢の最大値
	LPDIRECTINPUTDEVICE8	m_pKeyDevice;						//!< キーボード用デバイス
	State					m_currentKeyKind[m_kMaxKeyByte];	//!< どのキーが押されたかを格納している変数
	BYTE					m_oldKeyKind[m_kMaxKeyByte];		//!< 前のキーの状態を格納する変数
	BYTE					m_DIKeys[m_kMaxKeyByte];			//!< DIKを格納する変数
#pragma endregion
};

#endif // !INPUTKEY_H