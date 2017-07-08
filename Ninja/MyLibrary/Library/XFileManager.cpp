/**
 * @file	XFileManager/cpp
 * @breif	Xファイルの読み込みと描画を管理するクラス実装
 * @author	shibata
 */

#include "XFileManager.h"
#include "XFile.h"
#include "CommoSystem.h"

XFileManager::XFileManager()
{

}

XFileManager::~XFileManager()
{
	ReleaseAllXFile();
}

void XFileManager::Load(int index_, const char* filePath_)
{
	m_pXFile.emplace_back(New XFile);
	m_pXFile[index_]->Load(filePath_);
}

void XFileManager::DrawXFile(int index_)
{
	m_pXFile[index_]->DrawXFile();
}

LPD3DXMESH XFileManager::GetMeshData(int index_) const
{
	return m_pXFile[index_]->GetMeshData();
}

void XFileManager::ReleaseAllXFile()
{
	for (auto& itr : m_pXFile)
	{
		delete itr;
	}
}

void XFileManager::ReleaseXFile(int index_)
{
	if (m_pXFile[index_] != NULL)
	{
		delete m_pXFile[index_];
		m_pXFile[index_] = NULL;
	}
}