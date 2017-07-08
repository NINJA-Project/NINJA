/**
 * @file	SoundFileManager.cpp
 * @breif	音楽の読み込みと再生を管理しているクラス実装
 * @author	shibata
 */

#include "SoundFileManager.h"
#include "SoundFile.h"
#include "CommoSystem.h"

SoundFileManager::SoundFileManager()
{

}

SoundFileManager::~SoundFileManager()
{
	ReleaseAllSoundData();
}

void SoundFileManager::LoadSoundFile(int index_, const char* filePath_)
{
	m_pSoundFile.emplace_back(New SoundFile);
	m_pSoundFile[index_]->Load(filePath_);
}

void SoundFileManager::SoundState(int index_, SoundMode soundMode_)
{
	m_pSoundFile[index_]->SoundState(static_cast<SoundFile::Mode>(soundMode_));
}

void SoundFileManager::ReleaseAllSoundData()
{
	// @todo itrの変数名を後々変更する
	for (auto& itr : m_pSoundFile)
	{
		delete itr;
	}
}

void SoundFileManager::ReleaseSoundData(int index_)
{
	if (m_pSoundFile[index_] != NULL)
	{
		delete m_pSoundFile[index_];
		m_pSoundFile[index_] = NULL;
	}
}