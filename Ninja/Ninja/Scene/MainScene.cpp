/**
* @file		MainScene.cpp
* @breif	メインシーンのクラス実装
* @atuhor	shibata
*/

#include <Library\DebugSystem.h>
#include <Library\Define.h>
#include "MainScene.h"
#include "../ObjectManager/ObjectManager.h"

MainScene::MainScene() : 
Scene(Scene::ID::MAIN_SCENE),
m_pObjectManager(New ObjectManager)
{
	MyAssert(m_pObjectManager, "データが入っていません");
}

MainScene::~MainScene()
{
	SafeDelete(m_pObjectManager);
}

Scene::ID MainScene::Control()
{
	// プレイヤーの挙動の更新 
	m_pObjectManager->Control();
	return Scene::ID::MAIN_SCENE;
}

void MainScene::Draw()
{
	m_pObjectManager->Draw();
}