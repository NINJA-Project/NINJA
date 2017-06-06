/**
 * @file	GameDataManager.h
 * @breif	�Q�[����̃f�[�^���Ǘ�����N���X�w�b�_
 * @author	shibata
 */

#ifndef GAMEDATAMANAGER_H
#define GAMEDATAMANAGER_H

/* 
���̃N���X����l�Ȃǂ��擾�������ꍇ��
���̃N���X���o�R���Ď擾���邱��
��{�C�����C���֐��Ŏ������邱��
*/
#include <Library\Singleton.h>

class GameDataManager : public Singleton<GameDataManager>
{
private:
	friend Singleton<GameDataManager>;
	GameDataManager();
	virtual ~GameDataManager();

public:

};


#endif // !GAMEDATAMANAGER_H