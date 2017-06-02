/**
* @file		LogoScene.cpp
* @breif	ロゴクラス実装
* @author	shibata
*/

#include "LogoScene.h"
#include <Library.h>

LogoScene::LogoScene() : 
Scene(Scene::ID::LOGO_SCENE)
{

}

LogoScene::~LogoScene()
{

}

Scene::ID LogoScene::Control()
{
	return Scene::ID::LOGO_SCENE;
}

void LogoScene::Draw()
{

}