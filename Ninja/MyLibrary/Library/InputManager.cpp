/**
 * @file	InputManager.cpp
 * @breif	入力機器の管理をしているクラス実装
 * @author	shibata
 */

#include "InputManager.h"
#include "KeyDevice.h"
#include "CommoSystem.h"

InputManager::InputManager() : 
m_pKeyDevice(New KeyDevice)
{
#if _DEBUG
	MyAssert(&m_pKeyDevice, "NULL");
#endif // _DEBUG
}

InputManager::~InputManager()
{
	SafeDelete(m_pKeyDevice);
}

void InputManager::UpdateDI()
{
	m_pKeyDevice->Update();
	// @todo マウス、ゲームパッドが実装され次第ここにUpdate関数をつける
}

void InputManager::UpdateKey()
{
	m_pKeyDevice->Update();
}

// @todo マウス、ゲームパッドが実装され次第新規で個別にUpdate関数をつける

InputManager::KeyState InputManager::ChooseKey(int dik_)
{
	KeyState state = static_cast<InputManager::KeyState>(m_pKeyDevice->ChooseKey(dik_));
	return state;
}