/**
* @file		MainScene.cpp
* @breif	メインシーンのクラス実装
* @atuhor	shibata
*/

#include <Library\DebugSystem.h>
#include <Library\Define.h>
#include "MainScene.h"
#include "../ObjectManager/ObjectManager.h"
#include "../ResourceManager/ResourceManager.h"

MainScene::MainScene() : 
Scene(Scene::ID::MAIN_SCENE),
m_pObjectManager(New ObjectManager)
{
	ResourceManager mainSceneResource;
	mainSceneResource.TexLoader(Scene::ID::MAIN_SCENE);
	MyAssert(m_pObjectManager, "データが入っていません");
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