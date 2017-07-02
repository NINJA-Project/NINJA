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

#pragma region シーン状態ID
private:
	enum State
	{
		CREATE,
		UPDATE,
		RELEASE
	};
#pragma endregion


#pragma region メンバ変数
private:
	SceneFactory*	m_pSceneFactory;
	Scene*			m_pScene;
	Scene::ID		m_nextSceneID;
	Scene::ID		m_currentSceneID;
	State			m_state;
	bool			m_isControlEnd;
#pragma endregion 
};

#endif // !SCENETRANSITION_H