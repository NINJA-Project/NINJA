/**
 * @file	Main.cpp
 * @breif	エントリーポイント
 * @author	shibata
 */

#include <Library.h>
#include <Library\DebugSystem.h>
#include <Library\Define.h>
#include "GameManager\GameManager.h"

namespace
{
	const int	clientWidth		= 1280;
	const int	clientHeight	= 720;
	const char*	title			= "Ninja";
	const int	gameFPS			= 60;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	Library*		pLibrary = &Library::Instance();
	DebugSystem*	pDebugSystem = New DebugSystem;
	GameManager*	pGameManager = NULL;

	pDebugSystem->CheckMemoryLeaK();

	pLibrary->InitLibrary(title, clientWidth, clientHeight, false);
	pLibrary->Init3DDraw();

	pGameManager = New GameManager;
	DWORD currentTime;
	DWORD oldTime = gameFPS * timeGetTime();

	while (!pLibrary->Update())
	{
		currentTime = gameFPS * timeGetTime();
		if (currentTime - oldTime >= 1000)
		{
			if (pGameManager->Update())
			{
				break;
			}
			oldTime += 1000;
			Sleep(10);
		}
	}
	SafeDelete(pDebugSystem);
	SafeDelete(pGameManager);
	return 0;
}