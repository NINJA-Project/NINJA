/**
* @file		TitleScene.cpp
* @breif	タイトルシーンクラス実装
* @author	shibata
*/

#include "TitleScene.h"
#include "../ResourceManager/ResourceManager.h"

TitleScene::TitleScene() : 
Scene(Scene::ID::TITLE_SCENE)
{
	ResourceManager::Instance().TexLoader(Scene::ID::TITLE_SCENE);
}

TitleScene::~TitleScene()
{

}

Scene::ID TitleScene::Control()
{
	return Scene::ID::TITLE_SCENE;
}

void TitleScene::Draw()
{

}