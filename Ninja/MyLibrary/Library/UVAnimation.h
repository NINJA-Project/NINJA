/**
 * @file	UVAnimation.h
 * @breif	UVアニメーションクラスヘッダ
 * @author	shibata
 */

#ifndef UVANIMATION_H
#define UVANIMATION_H

#include "fRect.h"
#include <vector>

class UVAnimation
{
public:
	/**コンストラクタ*/
	UVAnimation();
	/**デストラクタ*/
	~UVAnimation();

	/**
	 * アニメーションのデータを設定する関数
	 * @param [in] 
	 * @param [in] 
	 * @param [in] 
	 * @param [in] 
	 */
	void CreateAnimationData(int tuCount_, int tvCount_, const fRect moveUVval_, float changeFlameTime_);

	/**
	* アニメーションの更新関数
	* @retval		true		更新完了
	* @retval		false		更新失敗
	*/
	bool UpData();

	/**
	 * アニメーションデータを入れ込む関数
	 * @param [in] animeNum_		1種類のアニメーションの枚数
	 * @param [in] isReverse_		反転アニメーションをさせるかどうか
	 */
	void SetAnimetionData(int animeNum_, bool isReverse_);

	/**
	 * 矩形情報の取得関数
	 * @return m_currntAnimeData.UV 現在のUV
	 */
	fRect GetRect() const
	{
		return m_currntAnimeData.UV;
	}

#pragma region メンバ変数
private:
#pragma region アニメーションデータ構造体
	struct AnimationData
	{
		fRect	UV;
		float	changeUVFlame;

		AnimationData(const fRect& texUV_, float flame) :
		UV(texUV_),
		changeUVFlame(flame)
		{}
	};
#pragma endregion
	std::vector<AnimationData>	m_animeData;
	std::vector<int>			m_animeNumber;
	AnimationData				m_currntAnimeData;
	bool						m_isReverse;
	int							m_currentFlame;
#pragma endregion
};

#endif // !UVANIMATION_H