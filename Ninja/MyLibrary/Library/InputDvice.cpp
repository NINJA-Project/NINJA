/**
 * @file	InputDevice.cpp
 * @breif	入力機器の初期化クラス実装
 * @author	shibata
 */

#include "InputDvice.h"
#include "CommoSystem.h"
#include "Directives.h"

InputDevice::InputDevice() :
m_pDinput(NULL),
m_pKeyDevice(NULL)
{

}

InputDevice::~InputDevice()
{

	SafeRelease(m_pKeyDevice);
	SafeRelease(m_pDinput);
}

void InputDevice::Initialize(HWND hwnd_)
{
	if (FAILED(DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8,
		(VOID**)&m_pDinput, NULL)))
	{
		MyAssert(m_pDinput, "初期化に失敗しました");
	}

#ifdef KEY
	InitializeKeyDevice(hwnd_);
#elif defined(MOUSE)
	InitializeMouseDevice(hwnd_);
#elif defined(GAMEPAD)

#endif
}

void InputDevice::InitializeKeyDevice(HWND hwnd_)
{
	if (FAILED(m_pDinput->CreateDevice(GUID_SysKeyboard, &m_pKeyDevice, NULL)))
	{
		MyAssert(m_pKeyDevice, "デバイスの初期化に失敗しました");
	}

	//	データフォーマット
	if (FAILED(m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		MyAssert(m_pKeyDevice, "データフォーマットの設定に失敗しました");
	}

	//	協調レベル
	if (FAILED(m_pKeyDevice->SetCooperativeLevel(hwnd_, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
	{
		MyAssert(m_pKeyDevice, "協調レベルの設定に失敗しました");
	}

	// アクセス許可
	m_pKeyDevice->Acquire();
}

void InputDevice::InitializeMouseDevice(HWND hwnd_)
{
}