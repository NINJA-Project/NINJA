/**
* @file		Ui.cpp
* @breif	UI�̐e�N���X����
* @author	shibata
*/

#include "Ui.h"
#include <Library.h>
#include "../GameDataManager/GameDataManager.h"

Ui::Ui() : 
m_rLibrary(Library::Instance()),
m_pos(0.0f, 0.0f),
m_pGameData(&GameDataManager::Instance())
{

}

Ui::~Ui()
{

}