/**
 * @file	TextureFile.h
 * @breif	画像ファイルの読み込みクラスヘッダ
 * @author	shibata
 */

#ifndef TEXTUREFILE_H
#define TEXTUREFILE_H

#include <d3dx9.h>
#include "RGBAColor.h"


class TextureFile
{
public:
	/**コンストラクタ*/
	TextureFile();
	/**デストラクタ*/
	~TextureFile();

	/**
	 * 画像を読み込む関数
	 * @param [in]	filePath_	画像のファイルパス
	 */
	void Load(const char* filePath_);

	/**
	 * 画像を詳細に読み込む関数
	 * @param [in]	filePath_		画像のファイルパス
	 * @param [in]	color_			RGBAの色設定
	 * @param [in]	isTowPower_		画像サイズの2の累乗がどうか		@note isTowPower_のデフォルト値はLibraryクラスにて true に設定
	 */
	void LoadMoreInfo(const char* filePath_, const RGBAColor& color_, bool isTwoPower_);

	/**
	 * 画像データの取得関数
	 * @return m_pTexture 画像データ
	 */
	LPDIRECT3DTEXTURE9 GetTextureFileData() const
	{
		return m_pTexture;
	}

#pragma region メンバ変数
private:
	LPDIRECT3DTEXTURE9	m_pTexture;			//!< DirectXのテクスチャインターフェイス
	LPDIRECT3DDEVICE9	m_pGraphicsDevice;	//!< DirectX9から取ってきたデバイス
#pragma endregion
};

#endif // !TEXTUREFILE_H