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
	~GameDataManager();

public:
	void SetPlayerLife(const int life_)
	{
		m_playerLife = life_;
	}

	int GetPlayerLife() const
	{
		return m_playerLife;
	}

	void SetScore(const int score_)
	{
		m_currentScore = score_;
	}

	int GetScore() const
	{
		return m_currentScore;
	}

#pragma region �����o�ϐ�
private:
	int m_playerLife;
	int m_currentScore;
#pragma endregion
};

#endif // !GAMEDATAMANAGER_H