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
	 * @param [in] isFullScreen_	フルスクリーンかどうか		@note isFullScreen_のデフォルト値はLibraryクラスにて false に設定
	 */
	void Create(const char* pWindowName_, int clientWidth_, int clientHeight_, bool isFullScreen_);

	/**ウィンドウの更新関数*/
	bool Update();

	/**
	 * ウィンドウハンドルの取得関数
	 * @return m_hWnd ウィンドウハンドルのデータ
	 */
	HWND GetHwnd() const
	{
		return m_hwnd;
	}

	/**
	* ウィンドの横幅取得関数
	* @return m_clientWidth ウィンドウの横幅
	*/
	int GetWidth() const
	{
		return m_clientWidth;
	}

	/**
	* ウィンドウの縦幅取得関数
	* @return m_clientHeight ウィンドウの縦幅
	*/
	int GetHeight() const
	{
		return m_clientHeight;
	}

#pragma region メンバ変数
private:
	int 	m_clientWidth;		//!< ウィンドウの横幅
	int 	m_clientHeight;		//!< ウィンドウの縦幅
	HWND	m_hwnd;				//!< ウィンドウハンドル
	MSG		m_msg;				//!< メッセージ情報を格納する
#pragma endregion

};

#endif // !WINDOWCREATE_H