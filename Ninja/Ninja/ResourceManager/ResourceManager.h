/**
 * @file	ResourceManager.h
 * @breif	�Q�[����ŕK�v�ȃ��\�[�X�ǂݍ��݃N���X�w�b�_
 * @author	shibata
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "../Scene/Scene.h"

class Library;

class ResourceManager
{
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
	};
#pragma endregion
#pragma region �}�b�v�`�b�vID
	enum ChipID
	{
		NONE,			// �Ȃɂ��Ȃ�
		NORMAL_BLOCK,	// �ʏ�̃u���b�N
		LANDING_BLOCK,	// ����u���b�N
		LANDING_BLOCK2,	// ���̖��O
	};
#pragma endregion


public:
	ResourceManager();
	~ResourceManager();

	void TexLoader(Scene::ID currentID_);
	void CSVLoader();

private:
	Library&	m_rLibrary;
	const int	m_kCsvWidth;		// csv�̕�
	const int	m_kCsvHeight;		// csv�̍���
};

#endif // !RESOURCEMANAGER_H