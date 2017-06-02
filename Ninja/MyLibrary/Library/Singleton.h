/**
 * @file	Singleton.h
 * @breif	
 * @author	shibata
 */

#ifndef SINGLETON_H
#define SINGLETON_H

#include "DebugSystem.h"

template<class Type>
class Singleton
{
public:
	static Type& Instance()
	{
		static Type m_instance;
		return m_instance;
	}

protected:
	Singleton() {}

	virtual ~Singleton(){}
private:
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;
};

#endif // !SINGLETON_H