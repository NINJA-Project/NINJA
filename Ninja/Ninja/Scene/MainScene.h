/**
 * @file	MainScene.h
 * @breif	メインシーンのクラスヘッダ
 * @atuhor	shibata
 */

#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "Scene.h"

class MainScene : public Scene
{
public:
	MainScene();
	virtual ~MainScene();

	virtual Scene::ID Control();
	virtual void Draw();
};

#endif // !MAINSCENE_H