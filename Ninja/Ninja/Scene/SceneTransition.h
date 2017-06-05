/**
 * @file	SceneTransition.h
 * @breif	シーン遷移のクラスヘッダ
 * @author	shibata
 */

#ifndef SCENETRANSITION_H
#define SCENETRANSITION_H

#include "Scene.h"
class SceneFactory;

class SceneTransition
{
public:
	SceneTransition();
	~SceneTransition();

	bool Control();
	void Render();

private:
	enum State
	{
		CREATE,
		RUN,
		RELEASE
	};

private:
#pragma region メンバ変数
	SceneFactory*	m_pSceneFactory;
	Scene*			m_pScene;
	Scene::ID		m_nextSceneID;
	Scene::ID		m_currentSceneID;
	State			m_state;
	bool			m_isControlEnd;
#pragma endregion 
};

#endif // !SCENETRANSITION_H