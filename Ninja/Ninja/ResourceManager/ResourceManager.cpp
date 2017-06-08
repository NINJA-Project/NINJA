/**
 * @file	ResourceManager.cpp
 * @breif	�Q�[����ŕK�v�ȃ��\�[�X�ǂݍ��݃N���X����
 * @author	shibata
 */


#include "ResourceManager.h"
#include "../Scene/Scene.h"
#include <Library.h>
#include <stdio.h>

namespace
{
	int g_csvMap[15][20];
}

ResourceManager::ResourceManager() :
m_rLibrary(Library::Instance()),
m_kCsvWidth(15),
m_kCsvHeight(20)
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
		break;
	}
}

void ResourceManager::CSVLoader()
{
	FILE* fp;
	fopen_s(&fp, "Resource/File/NinjaMap.csv", "r");
	MyAssert(fp, "�f�[�^�������Ă��܂���");

	/*
	�G�l�~�[��S�[���|�C���g�z�u���Ɏg�p����
	for (int i = 0; i < m_kCsvHeight; i++)
	{
		for (int j = 0; j < m_kCsvWidth; j++)
		{
			fscanf_s(fp, "%d,", g_csvMap[i][j],sizeof(int));
			switch (g_csvMap[i][j])
			{

			}
		}
	}
	*/

	fclose(fp);
}
