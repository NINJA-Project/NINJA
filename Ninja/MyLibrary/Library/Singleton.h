/**
 * @file	Singleton.h
 * @breif	
 * @author	shibata
 */

#ifndef SINGLETON_H
#define SINGLETON_H

#include "Debug.h"

template<class Type>
class Singleton
{
public:
	/**
	* インスタンス取得関数
	* @return m_instance インスタンス情報
	*/
	static Type& GetInstance()
	{
		if (!m_isCreateInstace)
		{
			MyAssert(&m_instance, "NULLが入っており生成できません");
			CreateInstace();
		}
		
		return *m_instance;
	}

protected:
	Singleton() {}
	virtual ~Singleton() { DestroyInstance(); }

private:
#pragma region メンバ関数
	/**インスタンス生成関数*/
	static void CreateInstace()
	{
		m_isCreateInstace = true;
		m_instance = New Type;
	}

	/**インスタンス削除関数*/
	static void DestroyInstance()
	{
		delete m_instance;
	}

	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;
#pragma endregion

#pragma region メンバ変数
private:
	static Type* m_instance;		// インスタンス変数
	static bool	m_isCreateInstace;	// インスタンスが生成されたかどうか
#pragma endregion
};

#pragma region 静的メンバ変数の初期化
template<typename Type>
bool Singleton<Type>::m_isCreateInstace = false;

template<typename Type>
Type* Singleton<Type>::m_instance = nullptr;
#pragma endregion
#endif // !SINGLETON_H