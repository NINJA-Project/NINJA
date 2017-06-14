/**
 * @file	GameManager.h
 * @breif	アプリケーションの基点クラスヘッダ
 * @author	shibata
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class Library;
class SceneTransition;

class GameManager
{

public:
	GameManager();
	~GameManager();

	bool Update();

private:
#pragma region メンバ変数
	Library&			m_rLibrary;
	SceneTransition*	m_pSceneTransition;
	bool				m_isGameEnd;
#pragma endregion
};

#endif // !APPLICATION_H