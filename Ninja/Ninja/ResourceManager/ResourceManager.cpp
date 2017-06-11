/**
 * @file	ResourceManager.cpp
 * @breif	�Q�[����ŕK�v�ȃ��\�[�X�ǂݍ��݃N���X����
 * @author	shibata
 */


#include "ResourceManager.h"
#include "../Scene/Scene.h"
#include <Library.h>
#include <fstream>
#include <iostream>
#include <sstream>

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
		m_rLibrary.LoadTextureFile(MAP_CHIP1, "Resource/Texture/MapChip.png");
		m_rLibrary.LoadTextureFile(MAP_CHIP2, "Resource/Texture/MapChip.png");
		m_rLibrary.LoadTextureFile(MAP_CHIP3, "Resource/Texture/MapChip.png");
		break;
	}
}

bool ResourceManager::CSVLoader(std::vector<std::vector<std::string>>& data_, const char delim_)
{
	std::ifstream csvFile("Resource/File/NinjaMap.csv");
	MyAssert(csvFile, "�f�[�^�������Ă��܂���");

	std::string buf;

	while (getline(csvFile, buf))
	{
		std::vector<std::string> rec;
		std::istringstream iss(buf);
		std::string field;

		while (getline(iss, field, delim_))
		{
			rec.push_back(field);
		}

		if (rec.size() != 0)
		{
			data_.push_back(rec);
		}
	}


	return true;
}