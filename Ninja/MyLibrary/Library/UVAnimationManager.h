/**
 * @file	UVAnimationManager.h
 * @breif	�A�j���[�V�����N���X�̊Ǘ��N���X�w�b�_
 * @author	shibata
 */

#ifndef UVANIMATIONMANAGER_H
#define UVANIMATIONMANAGER_H

#include <vector>
#include "fRect.h"

class UVAnimation;

class UVAnimationManager
{
public:
	UVAnimationManager();
	~UVAnimationManager();

	/**
	* �A�j���[�V�����̍X�V�֐�
	* @param [in]	drawIndex_	
	* @retval		true		�X�V����
	* @retval		false		�X�V���s
	*/
	bool UpData(int drawIndex_);

	/**
	* �A�j���[�V�����f�[�^����ꍞ�ފ֐�
	* @param [in] drawIndex_
	* @param [in] animeNum_			1��ނ̃A�j���[�V�����̖���
	* @param [in] isReverse_		���]�A�j���[�V�����������邩�ǂ���
	*/
	void SetAnimetionData(int drawIndex_, int animeNum_, bool isReverse_);

	/**
	 * ��`���̎擾�֐�
	 * @param [in] drawIndex_		�`�悷��A�j���[�V�����̔z��ԍ�
	 * @return m_currntAnimeData.UV ���݂�UV
	 */
	fRect GetRect(int drawIndex_);


#pragma region �����o�ϐ�
private:
	std::vector<UVAnimation*> m_pUVAnimation;
#pragma endregion
};

#endif // !UVANIMATIONMANAGER_H