/**
 * @file	WindowCreate.h
 * @breif	ウィンドウを生成するクラスヘッダ
 * @author	shibata
 */

#ifndef WINDOWCREATE_H
#define WINDOWCREATE_H

#include <Windows.h>

class Window
{
public:
	/**コンストラクタ*/
	Window();
	/**デストラクタ*/
	~Window();

	/**
	 * ウィンドウの生成関数
	 * @param [in] pWindowName_		ゲームのタイトル
	 * @param [in] clientWidth_		画面横幅のサイズ
	 * @param [in] clientHeiht_		画面縦幅のサイズ
	 * @param [in]	isFullScreen_	フルスクリーンかどうか		@note デフォルトはLibraryクラスで false に設定している
	 */
	void Create(const char* pWindowName_, int clientWidth_, int clientHeight_, bool isFullScreen_);

	bool Update();

	/**
	 * ウィンドウハンドルの取得関数
	 * @return m_hWnd ウィンドウハンドルのデータ
	 */
	HWND GetHwnd()
	{
		return m_hwnd;
	}

	int GetWidth()
	{
		return m_clientWidth;
	}

	int GetHeight()
	{
		return m_clientHeight;
	}

private:
	int 	m_clientWidth;
	int 	m_clientHeight;
	HWND	m_hwnd;				//!< ウィンドウハンドル
	MSG		m_msg;
};

#endif // !WINDOWCREATE_H