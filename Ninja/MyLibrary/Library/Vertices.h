/**
 * @file	Vertices.h
 * @breif	頂点情報を決めるクラスヘッダ
 * @author	shibata
 */

#ifndef VERTICES_H
#define VERTICES_H

#include <d3dx9.h>
#include "Vector2D.h"
#include "Vector3D.h"
#include "RGBAColor.h"
#include "fRect.h"

class Vertices
{
public:
	/**コンストラクタ*/
	Vertices();
	/**デストラクタ*/
	~Vertices();

	/**
	 * 画像サイズの設定する関数
	 * @param [in] width_	描画の横幅
	 * @param [in] height_	描画の縦幅
	 * @param [in] UV_		UVの値						@note UV_のデフォルト値はLibraryクラスにて各々設定している
	 * @param [in] depth_	描画の奥行き				@note depth_のデフォルト値はLibraryクラスにて 0.5f に設定
	 */
	void SetTexSize(float width_, float height_, const fRect& UV_, float depth_);

	/**
	 * 左上からの描画関数
	 * @param [in] position_		xy座標
	 * @param [in] pTextureData_	テクスチャデータ	@note Libraryクラスにてテクスチャデータを取得してくる
	 */
	void DrawLeftTop(const Vector2D& position_, const LPDIRECT3DTEXTURE9& pTextureData_);

	/**
	* 中心からの描画関数
	* @param [in] position_		xy座標
	* @param [in] pTextureData_	テクスチャデータ		@note Libraryクラスにてテクスチャデータを取得してくる
	*/
	void DrawCenter(const Vector2D& position_, const LPDIRECT3DTEXTURE9& pTextureData_);

	/**
	 * 色の変更する関数
	 * @param [in] afterColor_	変更したRGBAの最終的な値
	 * @param [in] setColor_	変更するRGBAの値
	 */
	void SetColor(DWORD& afterColor_, const RGBAColor& setColor_);

	/**
	 * UV座標を変更する関数
	 * @param [in] currentUV_ 変更するUVの値
	 */
	void SetUV(const fRect& currentUV_);


#pragma region CUSTOMVERTEX
private:
	struct CUSTOMVERTEX
	{
		Vector3D	position;	//!< xyzの座標
		FLOAT		rhw;		//!< 同次座標
		DWORD		color;		//!< 色指定
		Vector2D	UV;			//!< UV座標
	};
#pragma endregion

#pragma region メンバ変数
private:
	LPDIRECT3DDEVICE9	m_pGraphicsDevice;	//!< DirectX9から取ってきたデバイス
	DWORD				m_colors[4];		//!< テクスチャの色
	float				m_texWidth;			//!< テクスチャの幅
	float				m_texHeight;		//!< テクスチャの高さ
	float				m_texDepth;			//!< テクスチャの奥行き
	float				m_texMaxTu;			//!< テクスチャのX軸最大座標
	float				m_texMaxTv;			//!< テクスチャのY軸最大座標
	float				m_texMinTu;			//!< テクスチャのX軸最小座標
	float				m_texMinTv;			//!< テクスチャのY軸最小座標
#pragma endregion
};

#endif // !VERTICES_H