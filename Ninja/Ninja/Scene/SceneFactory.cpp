/**
 * @file	SceneFactory.cpp
 * @breif	シーンの生成クラス実装
 * @author	shibata
 */

#include "SceneFactory.h"
#include "LogoScene.h"
#include "MainScene.h"
#include "TitleScene.h"
#include <Library\CommoSystem.h>

SceneFactory::SceneFactory()
{

}

SceneFactory::~SceneFactory()
{

}

Scene* SceneFactory::CreateScene(Scene::ID nextSceneID_)
{
	Scene* pScene = NULL;

	switch (nextSceneID_)
	{
	case Scene::ID::LOGO_SCENE:
		pScene = New LogoScene;
		break;
	case Scene::ID::TITLE_SCENE:
		pScene = New TitleScene;
		break;
	case Scene::ID::MAIN_SCENE:
		pScene = New MainScene;
		break;
	}
	return pScene;
}