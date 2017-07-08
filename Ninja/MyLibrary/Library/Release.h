/**
 * @file	Release.h
 * @breif	解放関数のテンプレート化ヘッダ
 * @author	shibata
 */

#ifndef RELEASE_H
#define RELEASE_H

// Release関数を使う開放関数
template<typename Type>
void SafeRelease(Type& type_)
{
	if (type_ != NULL)
	{
		type_->Release();
		type_ = NULL;
	}
}

// 動的に確保したものを開放する関数
template<typename Type>
void SafeDelete(Type& type_)
{
	if (type_ != NULL)
	{
		delete type_;
		type_ = NULL;
	}
}

// 動的配列の開放関数
template<typename Type>
void SafeArrayDelete(Type& type_)
{
	if (type_ != NULL)
	{
		delete[] type_;
		type_ = NULL;
	}
}

#endif // !RELEASE_H