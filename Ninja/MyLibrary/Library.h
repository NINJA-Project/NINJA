/**
 * @file	Library.h
 * @breif	ライブラリ全体の統括クラスヘッダ
 * @author	shibata
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include <d3dx9.h>
#include "Library\Singleton.h"
#include <vector>
#include"Library\fRect.h"


#pragma region 前方宣言
class GraphicsDevice;
class InputManager;
class InputDevice;
class SoundDevice;
class Window;
class TextureFileManager;
class VertexManager;
class SoundFileManager;
class XFileManager;
class UVAnimationManager;
#pragma endregion 

#pragma region サウンド状態のenum
enum SoundMode
{
	PLAY,
	LOOP,
	STOP,
	RESET,
	RESET_PLAY,
	RESET_STOP,
};
#pragma endregion

#pragma region キー状態のenum
enum KeyState
{
	PUSH,
	RELEASE,
	ON,
	OFF
};
#pragma endregion

class Library : public Singleton<Library>
{
private:
	friend Singleton<Library>;
	/**コンストラクタ*/
	Library();
	/**デストラクタ*/
	~Library();
#pragma region 頂点フォーマット
	// メンバ変数のところにこの変数を置くとGraphicsDeviceのSetFVFでデフォルト設定できないため
	static const DWORD D3DFVF_CUSTOMVERTEX = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);		//!< 頂点フォーマット
#pragma endregion

public:		// Libraryクラスのパブリック関数

	/**
	 * ライブラリ初期化関数
	 * @param [in] pWindowName_		ウィンドウタイトル
	 * @param [in] clientWidth_		画面横幅のサイズ
	 * @param [in] clientHeiht_		画面縦幅のサイズ
	 * @param [in] isFullScreen_	フルスクリーンかどうか		@note isFullScreen_のデフォルト値は false 
	 */
	void Initialize(const char* pWindowName_, int clientWidth_, int clientHeight_, bool isFullScreen_ = false);


#pragma region Windowクラスのパブリック関数
	/**ウィンドウの更新関数*/
	bool UpdateWindow();

	/**
	 * ウィンドウ幅のサイズを取得してくる関数
	 * @return ウィンドウ幅
	 */
	int GetWinWidth();

	/**
	 * ウィンドウ高さのサイズを取得してくる関数
	 * @return ウィンドウ高さ
	 */
	int GetWinHeight();
#pragma endregion

#pragma region GraphicsDeviceクラスのパブリック関数
	/**
	* 頂点フォーマット設定関数
	* @param [in] fvf_ 頂点フォーマットの設定				@note fvf_のデフォルト値は D3DFVF_CUSTOMVERTEX
	*/
	void SetFVF(const DWORD fvf_ = D3DFVF_CUSTOMVERTEX);

	/**描画開始関数*/
	void RenderStarting();

	/**描画終了関数*/
	void RenderEnding();

	/**
	 * デバイス取得関数
	 * @return デバイス情報
	 */
	LPDIRECT3DDEVICE9 GetDevice();
#pragma endregion 

#pragma region InputManagerクラスのパブリック関数
	/**DI系をすべて更新する関数*/
	void UpdateDI();

	/**キーだけを更新する関数*/
	void UpdateKey();

	/**
	* キーの状態を決める関数
	* @param [in]		dik_	どのキーを使うか
	* @return			state	キーの状態
	*/
	KeyState ChooseKey(int dik_);
#pragma endregion 

#pragma region TextureFileManagerクラスのパブリック関数
	/**
	* 画像を読み込む関数
	* @param [in]	index_		読み込む画像の配列番号
	* @param [in]	filePath_	画像のファイルパス
	*/
	void LoadTexture(int index_, const char* filePath_);

	/**
	* 画像を詳細に読み込む関数
	* @param [in]	index_			読み込む画像の配列番号
	* @param [in]	filePath_		画像のファイルパス
	* @param [in]	alpha_			画像の透過の値					
	* @param [in]	red_			画像の赤の値					
	* @param [in]	green_			画像の緑の値					
	* @param [in]	blue_			画像の青の値					
	* @param [in]	isTowPower_		画像サイズの2の累乗がどうか		@note isTowPower_のデフォルト値は false 
	*/
	void LoadTextuerMoreInfo(int index_, const char* filePath_, int alpha_, int red_, int green_, int blue_, bool isTwoPower_ = true);

	/**全てのテクスチャの解放関数*/
	void ReleaseAllTexture();

	/**
	* 一部のテクスチャの解放関数
	* @param [in] index_	解放する配列番号
	*/
	void ReleaseTexture(int index_);
#pragma endregion

#pragma region VerticesManagerのパブリック関数
	/**
	 * 画像サイズの設定する関数
	 * @param [in] loadIndex_	LoadTextureで読み込んだ画像の配列番号
	 * @param [in] drawIndex_	描画する頂点情報の配列番号
	 * @param [in] width_		描画の横幅
	 * @param [in] height_		描画の縦幅
	 * @param [in] maxTu_		テクスチャの最大x座標		@note maxTu_のデフォルト値は 1.0f 
	 * @param [in] maxTv_		テクスチャの最大y座標		@note maxTv_のデフォルト値は 1.0f 
	 * @param [in] minTu_		テクスチャの最小x座標		@note minTu_のデフォルト値は 0.0f 
	 * @param [in] minTv_		テクスチャの最小y座標		@note minTv_のデフォルト値は 0.0f 
	 * @param [in] depth_		描画の奥行き				@note depth_のデフォルト値は 0.5f 
	 */
	void SetTexSize(int loadIndex_, int drawIndex_, float width_, float height_, float maxTu_ = 1.0f, float maxTv_ = 1.0f, float minTu_ = 0.0f, float minTv_ = 0.0f, float depth_ = 0.5f);

	/**
	 * 左上からの描画関数
	 * @param [in] loadIndex_	LoadTextureで読み込んだ画像の配列番号
	 * @param [in] drawIndex_	描画する頂点情報の配列番号
	 * @param [in] posX_		x座標
	 * @param [in] posY_		y座標
	 */
	void DrawLeftTop(int loadIndex_, int drawIndex_, float posX_, float posY_);

	/**
	 * 左上を起点に描画されアニメーションする関数
	 * @param [in] loadIndex_	LoadTextureで読み込んだ画像の配列番号
	 * @param [in] drawIndex_	描画する頂点情報の配列番号
	 * @param [in] posX_		x座標
	 * @param [in] posY_		y座標
	 */
	void DrawAnimeLeftTop(int loadIndex_, int drawIndex_, float posX_, float posY_);


	/**
	 * 中心からの描画関数
	 * @param [in] loadIndex_	LoadTextureで読み込んだ画像の配列番号
	 * @param [in] drawIndex_	描画する頂点情報の配列番号
	 * @param [in] posX_		x座標
	 * @param [in] posY_		y座標
	 */
	void DrawCenter(int loadIndex_, int drawIndex_, float posX_, float posY_);

	/**
	 * 中心を起点に描画されアニメーションする関数
	 * @param [in] loadIndex_	LoadTextureで読み込んだ画像の配列番号
	 * @param [in] drawIndex_	描画する頂点情報の配列番号
	 * @param [in] posX_		x座標
	 * @param [in] posY_		y座標
	 */
	void DrawAnimeCenter(int loadIndex_, int drawIndex_, float posX_, float posY_);

	/**
	* 色の変更する関数
	*v@param [in] loadIndex_	LoadTextureで読み込んだ画像の配列番号
	* @param [in] drawIndex_	描画する頂点情報の配列番号
	* @param [in] color_		変更したRGBAの最終的な値
	* @param [in] alpha_		変更する透過の値
	* @param [in] red_			変更する赤の値
	* @param [in] green_		変更する緑の値
	* @param [in] blue_			変更する青の値
	*/
	void SetColor(int loadIndex_, int drawIndex_, DWORD color_, int alpha_, int red_, int green_, int blue_);

	/**全ての頂点データの解放関数*/
	void ReleaseAllVirtices();

	/**
	* 一部の頂点データの解放関数
	* @param [in] index_	解放する配列番号
	*/
	void ReleaseVirtices(int loadIndex_, int drawIndex_);
#pragma endregion

#pragma region SoundFileManagerクラスのパブリック関数
	/**
	* 音楽ファイル(wav)の読み込み関数
	* @param [in]	index_		読み込む音楽の配列番号
	* @param [in]	filePath_	音楽のファイルパス
	*/
	void LoadSoundFile(int index_, const char* filePath_);

	/**
	* 音楽の再生状態を決める関数
	* @param [in] index_		再生する音楽の配列番号
	* @pamra [in] soundMode_	音楽の再生状態
	*/
	void SoundState(int index_, SoundMode soundMode_);

	/**全てのサウンドデータの解放関数*/
	void ReleaseAllSoundData();

	/**
	* 一部のサウンドデータの解放関数
	* @param [in] index_	解放する配列番号
	*/
	void ReleaseSoundData(int index_);
#pragma endregion

#pragma region XFileManagerクラスのパブリック関数
	/**
	* Xファイルの読み込み関数
	* @param [in]	index_		読み込むXファイルの配列番号
	* @param [in]	filePath_	Xファイルのパス
	*/
	void LoadXFile(int index_, const char* filePath_);

	/**
	* Xファイルの描画関数
	* @param [in] index_		描画するXファイルの配列番号(読み込んだ配列番号と同じ)
	*/
	void DrawXFile(int index_);

	/**全てのXファイルの解放関数*/
	void ReleaseAllXFile();

	/**
	* 一部のXファイルの解放関数
	* @param [in] index_	解放する配列番号
	*/
	void ReleaseXFile(int index_);
#pragma endregion

#pragma region Fontクラスのパブリック関数
	/**
	* 文字を描画する関数
	* @param [in] pString_		描画する文字列
	* @param [in] posX_			描画する文字のX座標
	* @param [in] posY_			描画する文字のY座標
	* @param [in] format_		文字のフォーマット		@note format_のデフォルト値は 左寄せ
	* @param [in] red_			文字のR値				@note red_のデフォルト値は 255
	* @param [in] green_		文字のG値				@note green_のデフォルト値は 255
	* @param [in] blue_			文字のB値				@note blue_のデフォルト値は 255
	*/
	void DrawFont(const char* pString_, float posX_, float posY_, DWORD format_ = DT_LEFT, int red_ = 255, int green_ = 255, int blue_ = 255);

	/**
	* 文字を描画する関数
	* @param [in] width_		文字の幅
	* @param [in] height_		文字の高さ
	* @param [in] pString_		描画する文字列
	* @param [in] posX_			描画する文字のX座標
	* @param [in] posY_			描画する文字のY座標
	* @param [in] format_		文字のフォーマット		@note format_のデフォルト値は 左寄せ
	* @param [in] red_			文字のR値				@note red_のデフォルト値は 255
	* @param [in] green_		文字のG値				@note green_のデフォルト値は 255
	* @param [in] blue_			文字のB値				@note blue_のデフォルト値は 255
	*/
	void DrawFont(int width_, int height_, const char* pString_, float posX_, float posY_, DWORD format_ = DT_LEFT, int red_ = 255, int green_ = 255, int blue_ = 255);
#pragma endregion

#pragma region UVAnimationManagerのパブリック関数

#pragma endregion

#pragma region メンバ変数
private:
	GraphicsDevice*					m_pGraphicsDevice;
	InputDevice*					m_pInputDevice;
	SoundDevice*					m_pSoundDevice;
	InputManager*					m_pInputManager;
	Window*							m_pWindow;
	TextureFileManager*				m_pTextureFileManager;
	std::vector<VertexManager*>		m_pVertexManager;
	SoundFileManager*				m_pSoundFileManager;
	XFileManager*					m_pXFileManager;
	UVAnimationManager*				m_pUVAnimationManager;
#pragma endregion
};

#pragma region libファイル
#pragma comment(lib, "dsound.lib" )
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "Xinput.lib")
#pragma endregion
#endif // !LIBRARY_H