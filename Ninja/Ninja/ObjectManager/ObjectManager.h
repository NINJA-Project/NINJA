/**
 * @file	ObjectManager.h
 * @breif	ゲーム上のオブジェクトを管理するクラスヘッダ
 * @author	shibata
 */

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#pragma region 前方宣言
class MapManager;
class CharacterManager;
class UiManager;
#pragma endregion

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Control();
	void Draw();

#pragma region メンバ変数
private:
	MapManager*			m_pMapManager;
	CharacterManager*	m_pCharamanager;
	UiManager*			m_pUiManager;
#pragma endregion
};

#endif // !OBJECTMANAGER_H