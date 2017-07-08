/**
 * @file	XFileManager.h
 * @breif	Xファイルの読み込みと描画を管理するクラスヘッダ
 * @author	shibata
 */

#ifndef XFILEMANAGER_H
#define XFILEMANAGER_H

#include <vector>
#include <d3dx9.h>

class XFile;

class XFileManager
{
public:
	XFileManager();
	~XFileManager();

	/**
	* Xファイルの読み込み関数
	* @param [in]	index_		読み込むXファイルの配列番号
	* @param [in]	filePath_	Xファイルのパス
	*/
	void Load(int index_, const char* filePath_);

	/**
	 * Xファイルの描画関数
	 * @param [in] index_		描画するXファイルの配列番号(読み込んだ配列番号と同じ)
	 */
	void DrawXFile(int index_);

	/**
	* メッシュデータの取得関数
	* @param [in]	index_	Xファイルの配列番号
	* @return		m_pMesh メッシュデータ
	*/
	LPD3DXMESH GetMeshData(int index_) const;

	/**全てのXファイルの解放関数*/
	void ReleaseAllXFile();

	/**
	 * 一部のXファイルの解放関数
	 * @param [in] index_	解放する配列番号
	 */
	void ReleaseXFile(int index_);

#pragma region メンバ変数
private:
	std::vector<XFile*>	m_pXFile;
#pragma endregion
};

#endif // !XFILEMANAGER_H