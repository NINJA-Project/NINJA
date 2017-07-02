/**
* @file		MainScene.cpp
* @breif	メインシーンのクラス実装
* @atuhor	shibata
*/

#include <Library\CommoSystem.h>
#include "MainScene.h"
#include "../ObjectManager/ObjectManager.h"
#include "../ResourceManager/ResourceManager.h"

MainScene::MainScene() : 
Scene(Scene::ID::MAIN_SCENE),
m_pObjectManager(New ObjectManager)
{
	ResourceManager mainResource;
	mainResource.TexLoader(Scene::ID::MAIN_SCENE);
#if _DEBUG
	MyAssert(m_pObjectManager, "データが入っていません");
#endif // _DEBUG
}

MainScene::~MainScene()
{
	SafeDelete(m_pObjectManager);
}

Scene::ID MainScene::Control()
{
	m_pObjectManager->Control();
	return Scene::ID::MAIN_SCENE;
}

void MainScene::Draw()
{
	m_pObjectManager->Draw();
}