/**
 * @file	ObjectManager.h
 * @breif	�o�Ă���I�u�W�F�N�g���Ǘ����Ă���N���X�w�b�_
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

#pragma region �e�N�X�`��ID
public:
	enum TexID
	{
		MAP_CHIP_NORMAL,
	};
#pragma endregion

private:


};

#endif // !OBJECTMANAGER_H