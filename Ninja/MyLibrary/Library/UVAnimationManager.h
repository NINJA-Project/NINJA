/**
 * @file	UVAnimationManager.h
 * @breif	アニメーションクラスの管理クラスヘッダ
 * @author	shibata
 */

#ifndef UVANIMATIONMANAGER_H
#define UVANIMATIONMANAGER_H

#include <vector>
#include "fRect.h"

class UVAnimation;

class UVAnimationManager
{
public:
	UVAnimationManager();
	~UVAnimationManager();

	/**
	* アニメーションの更新関数
	* @param [in]	drawIndex_	
	* @retval		true		更新完了
	* @retval		false		更新失敗
	*/
	bool UpData(int drawIndex_);

	/**
	* アニメーションデータを入れ込む関数
	* @param [in] drawIndex_
	* @param [in] animeNum_			1種類のアニメーションの枚数
	* @param [in] isReverse_		反転アニメーションをさせるかどうか
	*/
	void SetAnimetionData(int drawIndex_, int animeNum_, bool isReverse_);

	/**
	 * 矩形情報の取得関数
	 * @param [in] drawIndex_		描画するアニメーションの配列番号
	 * @return m_currntAnimeData.UV 現在のUV
	 */
	fRect GetRect(int drawIndex_);


#pragma region メンバ変数
private:
	std::vector<UVAnimation*> m_pUVAnimation;
#pragma endregion
};

#endif // !UVANIMATIONMANAGER_H