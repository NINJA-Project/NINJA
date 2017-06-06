/**
 * @file	MainScene.h
 * @breif	メインシーンのクラスヘッダ
 * @atuhor	shibata
 */

#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "Scene.h"

class ObjectManager;

class MainScene : public Scene
{
public:
	MainScene();
	virtual ~MainScene();

	virtual Scene::ID Control();
	virtual void Draw();

private:
#pragma region メンバ変数
	ObjectManager*	m_pObjectManager;
#pragma endregion

};

#endif // !MAINSCENE_H