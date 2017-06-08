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
#include <vector>

class GameDataManager : public Singleton<GameDataManager>
{
private:
	friend Singleton<GameDataManager>;
	GameDataManager();
	virtual ~GameDataManager();

public:
	void SetCsvWidth(const int width_)
	{
		m_csvWidth = width_;
	}

	int GetCsvWidth() const
	{
		return m_csvWidth;
	}

	void SetCsvHeight(const int height_)
	{
		m_csvHeight = height_;
	}

	int GetCsvHeight() const
	{
		return m_csvHeight;
	}

private:
#pragma region �����o�ϐ�
	int m_csvWidth;
	int m_csvHeight;
	
#pragma endregion
};

#endif // !GAMEDATAMANAGER_H