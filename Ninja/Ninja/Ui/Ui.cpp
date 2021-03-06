/**
* @file		Ui.cpp
* @breif	UIの親クラス実装
* @author	shibata
*/

#include "Ui.h"
#include <Library.h>
#include "../GameDataManager/GameDataManager.h"

Ui::Ui() : 
m_rLibrary(Library::GetInstance()),
m_pos(0.0f, 0.0f),
m_pGameData(&GameDataManager::GetInstance())
{

}

Ui::~Ui()
{
	m_pGameData->DestroyInstance();
}