/**
* @file		SoundDevice.cpp
* @breif	サウンドの初期化クラス実装
* @author	shibata
*/

#include "SoundDevice.h"
#include "CommoSystem.h"

SoundDevice::SoundDevice() :
m_pDsound8(nullptr)
{

}

SoundDevice::~SoundDevice()
{
	SafeRelease(m_pDsound8);
}

void SoundDevice::Initialize(HWND hwnd_)
{
	if (FAILED(DirectSoundCreate8(NULL, &m_pDsound8, NULL)))			// オブジェクトの生成と初期化
	{
		MyAssert(m_pDsound8, "初期化に失敗しました");
	}

	if (FAILED(m_pDsound8->SetCooperativeLevel(hwnd_, DSSCL_PRIORITY)))		// 協調レベルの設定
	{
		MyAssert(m_pDsound8, "協調レベルの設定に失敗しました");
	}
}