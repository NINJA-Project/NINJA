/**
 * @file	InputManager.h
 * @breif	入力機器の管理をしているクラスヘッダ
 * @author	shibata
 */

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

class KeyDevice;

class InputManager
{
#pragma region キーの状態enum
private:
	enum KeyState
	{
		KEY_PUSH,
		KEY_RELEASE,
		KEY_ON,
		KEY_OFF,
	};
#pragma endregion

public:
	/**コンストラクタ*/
	InputManager();
	/**デストラクタ*/
	~InputManager();

	/**DI系をすべて更新する関数*/
	void UpdateDI();

	/**キーだけを更新する関数*/
	void UpdateKey();

	/**
	 * キーの状態を決める関数
	 * @param [in]		dik_	どのキーを使うか
	 * @return			state	キーの状態
	 */
	KeyState ChooseKey(int dik_);

#pragma region メンバ変数
private:
	KeyDevice*	m_pKeyDevice;
#pragma endregion
};

#endif // !INPUTMANAGER_H