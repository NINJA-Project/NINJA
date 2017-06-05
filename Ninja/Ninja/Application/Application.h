/**
 * @file	Application.h
 * @breif	アプリケーションの基点クラスヘッダ
 * @author	shibata
 */

#ifndef APPLICATION_H
#define APPLICATION_H

class Library;

class Application
{
public:
	Application();
	~Application();

	bool Run();

private:
#pragma region メンバ変数
	Library&	m_rLibrary;
	bool		m_isGameEnd;
#pragma endregion
};

#endif // !APPLICATION_H