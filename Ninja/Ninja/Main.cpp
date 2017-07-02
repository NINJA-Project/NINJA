/**
 * @file	Main.cpp
 * @breif	エントリーポイント
 * @author	shibata
 */

#include <Library.h>
#include <Library\CommoSystem.h>
#include "GameManager\GameManager.h"

namespace
{
	const int	clientWidth		= 1920;
	const int	clientHeight	= 1080;
	const char*	title			= "Ninja";
	const int	gameFPS			= 60;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	Library*		pLibrary = &Library::GetInstance();
	Debug*			pDebug = New Debug;
	GameManager*	pGameManager = NULL;

	pDebug->CheckMemoryLeaK();

	pLibrary->Initialize(title, clientWidth, clientHeight);

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
	SafeDelete(pDebug);
	SafeDelete(pGameManager);
	pLibrary->DestroyInstance();
	return 0;
}