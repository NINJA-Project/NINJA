/**
 * @file	ResourceManager.cpp
 * @breif	�Q�[����ŕK�v�ȃ��\�[�X�ǂݍ��݃N���X����
 * @author	shibata
 */


#include "ResourceManager.h"
#include "../Scene/Scene.h"
#include <Library.h>

ResourceManager::ResourceManager() :
m_rLibrary(Library::Instance())
{

}

ResourceManager::~ResourceManager()
{

}

void ResourceManager::TexLoader(Scene::ID currentID_)
{
	switch (currentID_)
	{
	case Scene::ID::LOGO_SCENE:
		// �����ɓǂݍ��ރe�N�X�`��������
		// �V�K�œǂݍ��ލۂ�h�̑Ή�����enum�Ƀe�N�X�`��ID��ǉ����邱��
		break;
	case Scene::ID::TITLE_SCENE:
		// �����ɓǂݍ��ރe�N�X�`��������
		// �V�K�œǂݍ��ލۂ�h�̑Ή�����enum�Ƀe�N�X�`��ID��ǉ����邱��

		break;
	case Scene::ID::MAIN_SCENE:
		// �����ɓǂݍ��ރe�N�X�`��������
		// �V�K�œǂݍ��ލۂ�h�̑Ή�����enum�Ƀe�N�X�`��ID��ǉ����邱��
		m_rLibrary.LoadTextureFile(MAP_CHIP, "Resource/Texture/MapChip.png");
		m_rLibrary.LoadTextureFile(ResourceManager::MainTex::Player_Standing1, "Resource/Texture/Player_Standing1.png");

		break;
	}
}

void ResourceManager::CSVLoader()
{

}
