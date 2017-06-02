/**
 * @file	DebugSystem.h
 * @breif	デバッグ機能が使用できるクラスヘッダ
 * @author	shibata
 */

#ifndef DEBUGSYSTEM_H
#define DEBUGSYSTEM_H

#include <crtdbg.h>
#include <Windows.h>

class DebugSystem
{
public:
	/**コンストラクタ*/
	DebugSystem();
	/**デストラクタ*/
	~DebugSystem();

	/**メモリリークのチェック関数*/
	void CheckMemoryLeaK();

	/**
	 * デバッグログに出力する関数
	 * @param [out] pString	出力する文字列
	 */
	static void OutputDebugLog(const char* pString_, ...);
};

// メモリを動的に確保するときに使うnewは必ずNewの方を使ってください
#ifdef _DEBUG
#define New new(_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define New new
#endif // _DEBUG

// 意図しない動作を防ぐためのマクロ
#ifdef _DEBUG
#define MyAssert(_expression, _str)																			\
if(!_expression)																							\
{																											\
	DebugSystem::OutputDebugLog(																			\
	"\n Assert! : %s ErrorLog: %s\n FileName: %s\n Line: %d\n\n", #_expression, _str, __FILE__, __LINE__);	\
	DebugBreak();																							\
}

#else
#define MyAssert(_expression, _str)

#endif // _DEBUG

#endif // !DEBUGSYSTEM_H