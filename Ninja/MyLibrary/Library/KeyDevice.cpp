/**
 * @file	KeyDevice.cpp
 * @breif	キーボード関連のクラス実装
 * @author	shibata
 */

#include "KeyDevice.h"
#include "InputDvice.h"

KeyDevice::KeyDevice() :
m_pKeyDevice(InputDevice::GetInstance().GetKeyDevice())
{
	for (int i = 0; i < m_kMaxKeyByte; i++)
	{
		m_oldKeyKind[i]			= KEY_OFF;
		m_currentKeyKind[i]		= KEY_OFF;
	}
}

KeyDevice::~KeyDevice()
{

}

void KeyDevice::Update()
{
	HRESULT result = m_pKeyDevice->Acquire();

	if ((result == DI_OK) || (result == S_FALSE))
	{
		m_pKeyDevice->GetDeviceState(sizeof(m_DIKeys), &m_DIKeys);
	}
}

KeyDevice::State KeyDevice::ChooseKey(int dik_)
{
	if (m_DIKeys[dik_] & 0x80)
	{
		if (m_oldKeyKind[dik_] == KEY_OFF)
		{
			m_currentKeyKind[dik_] = KEY_PUSH;
		}
		else
		{
			m_currentKeyKind[dik_] = KEY_ON;
		}
		m_oldKeyKind[dik_] = KEY_ON;
	}
	else
	{
		if (m_oldKeyKind[dik_] == KEY_ON)
		{
			m_currentKeyKind[dik_] = KEY_RELEASE;
		}
		else
		{
			m_currentKeyKind[dik_] = KEY_OFF;
		}
		m_oldKeyKind[dik_] = KEY_OFF;
	}

	return m_currentKeyKind[dik_];
}