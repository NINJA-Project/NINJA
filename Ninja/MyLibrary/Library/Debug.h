/**
 * @file	Debug.h
 * @breif	デバッグ機能が使用できるクラスヘッダ
 * @author	shibata
 */

#ifndef DEBUG_H
#define DEBUG_H

#include <crtdbg.h>
#include <Windows.h>

// メモリを動的に確保するときに使うnewは必ずNewの方を使ってください
#pragma region カスタムNewの定義
#ifdef _DEBUG
#define New new(_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define New new
#endif // _DEBUG
#pragma endregion
// 意図しない動作を防ぐためのマクロ
#pragma region カスタムAssertの定義
#define MyAssert(expression_, str_)																										\
if(!expression_)																														\
{																																		\
	Debug debug;																														\
	debug.OutputDebugLog("\nAssert!! : %s\n Factor : %s\n FileName : %s\n Line : %d\n\n", #expression_, str_, __FILE__, __LINE__);		\
	DebugBreak();																														\
}
#pragma endregion

class Debug
{
public:
	/**コンストラクタ*/
	Debug();
	/**デストラクタ*/
	~Debug();

	/**メモリリークのチェック関数*/
	void CheckMemoryLeaK();

	/**
	 * デバッグログに出力する関数
	 * @param [out] pString	出力する文字列
	 */
	void OutputDebugLog(const char* pString_, ...);
};

#endif // !DEBUG_H