/**
 * @file	TitleScene.h
 * @breif	タイトルシーンクラスヘッダ
 * @author	shibata
 */

#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene();
	virtual ~TitleScene();

	virtual Scene::ID Control();
	virtual void Draw();
};

#endif // !TITLESCENE_H