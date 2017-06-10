/**
 * @file	ResourceManager.h
 * @breif	�Q�[����ŕK�v�ȃ��\�[�X�ǂݍ��݃N���X�w�b�_
 * @author	shibata
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <Library\Singleton.h>
#include "../Scene/Scene.h"

class Library;

class ResourceManager : public Singleton<ResourceManager>
{
private:
	friend Singleton<ResourceManager>;
	ResourceManager();
	virtual ~ResourceManager();

public:
#pragma region ���S�V�[���̃e�N�X�`��ID
	enum LogoTex
	{
		LOGO
	};
#pragma endregion
#pragma region �^�C�g���V�[���̃e�N�X�`��ID
	enum TitleTex
	{
		TITLE_LOGO,
		BUTTON,
		START_LOGO,
		HOWTOPLAY_LOGO
	};
#pragma endregion
#pragma region ���C���V�[���̃e�N�X�`��ID
	enum MainTex
	{
		MAP_CHIP,
		Player_Standing1,		//�v���C���[�����G
		Player_Standeing2,		//�v���C���[�����G2
		Player_Run1,			//�v���C���[����
		Player_Run2,			//�v���C���[����2
		Player_Run3,			//�v���C���[����3
	};
#pragma endregion

public:
	void TexLoader(Scene::ID currentID_);
	void CSVLoader();

private:
	Library&	m_rLibrary;
};

#endif // !RESOURCEMANAGER_H