/**
* @file		Ui.h
* @breif	UIの親クラスヘッダ
* @author	shibata
*/

#ifndef UI_H
#define UI_H

#include <d3dx9.h>

class Library;
class GameDataManager;

class Ui
{
public:
	Ui();
	~Ui();

	virtual void Control() = 0;
	virtual void Draw() = 0;

protected:
	D3DXVECTOR2			m_pos;
	Library&			m_rLibrary;
	GameDataManager*	m_pGameData;
};

#endif // !UI_H