/**
 * @file	ObjectManager.h
 * @breif	出てくるオブジェクトを管理しているクラスヘッダ
 * @author	shibata
 */

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Control();
	void Draw();

#pragma region テクスチャID
public:
	enum TexID
	{
		MAP_CHIP_NORMAL,
	};
#pragma endregion

private:


};

#endif // !OBJECTMANAGER_H