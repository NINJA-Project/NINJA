/**
 * @file	GameManager.cpp
 * @breif	アプリケーションの基点クラス実装
 * @author	shibata
 */

#include "GameManager.h"
#include "../Scene/SceneTransition.h"
#include <Library.h>
#include <Library\DebugSystem.h>
#include <Library\Define.h>

GameManager::GameManager() :
m_rLibrary(Library::Instance()),
m_pSceneTransition(New SceneTransition),
m_isGameEnd(false)
{
	MyAssert(m_pSceneTransition, "データが入っていません");
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