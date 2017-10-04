/**
 * @file	VertexManager.h
 * @breif	頂点情報を管理しているクラスヘッダ
 * @author	shibata
 */

#ifndef VERTEXMANAGER_H
#define VERTEXMANAGER_H

#include <vector>
#include <d3dx9.h>
#include "fRect.h"

class Vertices;

class VertexManager
{
public:
	/**コンストラクタ*/
	VertexManager();
	/**デストラクタ*/
	~VertexManager();

	/**
	* 画像サイズの設定する関数
	* @param [in] index_	LoadTextureで読み込んだ画像の配列番号
	* @param [in] width_	描画の横幅
	* @param [in] height_	描画の縦幅
	* @param [in] UV_		UVの値						@note UV_のデフォルト値はLibraryクラスにて各々設定している
	* @param [in] depth_	描画の奥行き				@note depth_のデフォルト値はLibraryクラスにて 0.5f に設定
	*/
	void SetTexSize(int index_, float width_, float height_, const fRect& UV_, float depth_);

	/**
	* 左上からの描画関数
	* @param [in] index_		LoadTextureで読み込んだ画像の配列番号
	* @param [in] posX_			x座標
	* @param [in] posY_			y座標
	* @param [in] pTextureData_	テクスチャデータ				@note Libraryクラスにてテクスチャデータを取得してくる
	*/
	void DrawLeftTop(int index_, float posX_, float posY_, const LPDIRECT3DTEXTURE9& pTextureData_);

	/**
	* 中心からの描画関数
	* @param [in] index_		LoadTextureで読み込んだ画像の配列番号
	* @param [in] posX_			x座標
	* @param [in] posY_			y座標
	* @param [in] pTextureData_	テクスチャデータ				@note Libraryクラスにてテクスチャデータを取得してくる
	*/
	void DrawCenter(int index_, float posX_, float posY_, const LPDIRECT3DTEXTURE9& pTextureData_);

	/**
	* 色の変更する関数
	* @param [in] index_		LoadTextureで読み込んだ画像の配列番号
	* @param [in] afterColor_	変更したRGBAの最終的な値
	* @param [in] alpha_		変更する透過の値
	* @param [in] red_			変更する赤の値
	* @param [in] green_		変更する緑の値
	* @param [in] blue_			変更する青の値
	*/
	void SetColor(int index_, DWORD& afterColor_, int alpha_, int red_, int green_, int blue_);

	/**
	* UV座標を変更する関数
	* @pamra [in] index_		LoadTextureで読み込んだ画像の配列番号
	* @param [in] currentUV_	変更するUVの値
	*/
	void SetUV(int index_, const fRect& currentUV_);


	/**全ての頂点データの解放関数*/
	void ReleaseAllVirtices();

	/**
	 * 一部の頂点データの解放関数
	 * @param [in] index_	解放する配列番号
	 */
	void ReleaseVirtices(int index_);

#pragma region メンバ変数
private:
	std::vector<Vertices*>	m_pVertices;
#pragma endregion
};

#endif // !VERTICESMANAGER_H