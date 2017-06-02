/**
 * @file	Application.cpp
 * @breif	アプリケーションの基点クラス実装
 * @author	shibata
 */

#include "Application.h"
#include <Library.h>
#include <Library\DebugSystem.h>
#include <Library\Define.h>

Application::Application() : 
m_rLibrary(Library::Instance()),
m_isGameEnd(false)
{

}

Application::~Application()
{

}

bool Application::Run()
{

}