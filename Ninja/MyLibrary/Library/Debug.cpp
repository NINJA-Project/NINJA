/**
 * @file	Debug.cpp
 * @breif	デバッグ機能が使用できるクラスヘッダ
 * @author	shibata
 */

#include "Debug.h"
#include <stdarg.h>
#include <Windows.h>


namespace
{
	const int kDebugLogMax = 512;
}

Debug::Debug()
{

}

Debug::~Debug()
{

}

void Debug::CheckMemoryLeaK()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

void Debug::OutputDebugLog(const char* pString_)
{
	TCHAR outputStr[kDebugLogMax];
	va_list argsList;

	va_start(argsList, pString_);

	vsprintf_s(outputStr, sizeof(outputStr), pString_, argsList);
	OutputDebugString(outputStr);

	va_end(argsList);
}
