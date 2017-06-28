/**
 * @file	SceneFactory.h
 * @breif	シーンの生成をするクラスヘッダ
 * @author	shibata
 */

#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include "Scene.h"
#include <Library\Singleton.h>

class SceneFactory : public Singleton<SceneFactory>
{
private:
	friend Singleton<SceneFactory>;
	SceneFactory();
	virtual ~SceneFactory();

public:

	Scene* CreateScene(Scene::ID nextSceneID_);
};

#endif // !SCENEFACTORY_H