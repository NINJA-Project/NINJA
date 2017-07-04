/**
 * @file	SoundDevice.h
 * @breif	サウンドの初期化クラスヘッダ
 * @author	shibata
 */

#ifndef SOUNDDEVICE_H
#define SOUNDDEVICE_H

#include <dsound.h>
#include "Singleton.h"

class SoundDevice : public Singleton<SoundDevice>
{
private:
	friend Singleton<SoundDevice>;
	/**コンストラクタ*/
	SoundDevice();
	/**デストラクタ*/
	~SoundDevice();

public:
	/**
	 * 初期化関数
	 * @param [in]	hwnd_	ウィンドウハンドル
	 */
	void Initialize(HWND hwnd_);

	/**
	 * サウンドデバイスの取得関数
	 * @return m_pDsound8 サウンドデバイス情報
	 */
	IDirectSound8* GetSoundData() const
	{
		return m_pDsound8;
	}

#pragma region メンバ変数
private:
	IDirectSound8* m_pDsound8;	//!< サウンドインターフェイス
#pragma endregion
};

#endif // !SOUNDDEVICE_H