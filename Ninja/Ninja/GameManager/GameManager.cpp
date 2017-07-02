/**
 * @file	GameManager.cpp
 * @breif	アプリケーションの基点クラス実装
 * @author	shibata
 */

#include "GameManager.h"
#include "../Scene/SceneTransition.h"
#include <Library.h>
#include <Library\CommoSystem.h>

GameManager::GameManager() :
m_rLibrary(Library::GetInstance()),
m_pSceneTransition(New SceneTransition),
m_isGameEnd(false)
{
#if _DEBUG
	MyAssert(m_pSceneTransition, "データが入っていません");
#endif // _DEBUG
}

GameManager::~GameManager()
{
	SafeDelete(m_pSceneTransition);
}

bool GameManager::Update()
{
	m_rLibrary.UpdateDI();
	m_pSceneTransition->Control();

	m_rLibrary.SetFVF();
	m_rLibrary.DrawStart();
	m_pSceneTransition->Render();
	m_rLibrary.DrawEnd();

	return m_isGameEnd;
}