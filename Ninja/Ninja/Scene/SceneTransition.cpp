/**
 * @file	SceneTransition.cpp
 * @breif	シーンを遷移するクラス実装
 * @author	shibata
 */

#include "SceneTransition.h"
#include "Scene.h"
#include "SceneFactory.h"
#include <Library\CommoSystem.h>

SceneTransition::SceneTransition() :
m_pSceneFactory(&SceneFactory::GetInstance()),
m_pScene(NULL),
m_nextSceneID(Scene::ID::LOGO_SCENE),
m_currentSceneID(Scene::ID::LOGO_SCENE),
m_state(CREATE),
m_isControlEnd(false)
{
#if _DEBUG
	m_currentSceneID = Scene::ID::MAIN_SCENE;
	m_nextSceneID = Scene::ID::MAIN_SCENE;
#endif
}

SceneTransition::~SceneTransition()
{
	SafeDelete(m_pScene);
	m_pSceneFactory->DestroyInstance();
}

bool SceneTransition::Control()
{
	switch (m_state)
	{
	case CREATE:
		m_currentSceneID = m_nextSceneID;
		if (m_nextSceneID == Scene::ID::FINISH)
		{
			m_isControlEnd = true;
			return m_isControlEnd;
		}
		else
		{
			m_pScene = m_pSceneFactory->CreateScene(m_currentSceneID);
			m_state = UPDATE;
		}
		break;
	case UPDATE:
		if ((m_nextSceneID = m_pScene->Control()) != m_currentSceneID)
		{
			m_state = RELEASE;
		}
		break;
	case RELEASE:
		delete m_pScene;
		m_pScene = NULL;
		m_state = CREATE;
		break;
	}
	return m_isControlEnd;
}

void SceneTransition::Render()
{
	if (m_state == UPDATE && m_pScene != NULL)
	{
		m_pScene->Draw();
	}
}