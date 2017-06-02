/**
 * @file	Scene.cpp
 * @breif	シーンの親クラス実装
 * @author	shibata
 */

#include "Scene.h"
#include <Library.h>

Scene::Scene(Scene::ID sceneID_) :
m_rLibrary(Library::Instance())
{

}

Scene::~Scene()
{

}