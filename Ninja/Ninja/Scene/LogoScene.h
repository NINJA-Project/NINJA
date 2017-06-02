/**
 * @file	LogoScene.h
 * @breif	ロゴクラスヘッダ
 * @author	shibata
 */

#ifndef LOGOSCENE_H
#define LOGOSCENE_H

#include "Scene.h"

class LogoScene : public Scene
{
public:
	LogoScene();
	~LogoScene();

	Scene::ID Control();
	void Draw();
};

#endif // !LOGOSCENE_H