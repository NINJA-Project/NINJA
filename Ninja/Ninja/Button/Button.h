/**
 * @file	Button.h
 * @breif	ボタン関係のクラスヘッダ
 * @author	shibata
 */

#ifndef BUTTON_H
#define BUTTON_H

class Library;

class Button
{
public:
	/**
	* コンストラクタ
	* @param [in] posX_		Ｘ軸の表示位置
	* @param [in] posY_		Ｙ軸の表示位置
	* @param [in] texindex_	ボタンのID番号
	*/
	Button(float posX_, float posY_, int texindex_);
	/**デストラクタ*/
	~Button();

	/**
	* ボタンが押されたがどうかの関数
	* @retval true		押された
	* @retval false	押されてない
	*/
	bool IsPush();
	/**描画関数*/
	void Draw();

private:
	Library&	m_rLibrary;
	float		m_width;		// ボタンの描画時の幅
	float		m_height;		// ボタンの描画時の高さ
	float		m_posX;			// ボタンのX軸の位置
	float		m_posY;			// ボタンのY軸の位置
	int			m_texIndex;		// ボタンを描画するときのID番号
};

#endif // !BUTTON_H