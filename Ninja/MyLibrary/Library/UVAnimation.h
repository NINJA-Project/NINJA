/**
 * @file	UVAnimation.h
 * @breif	UV�A�j���[�V�����N���X�w�b�_
 * @author	shibata
 */

#ifndef UVANIMATION_H
#define UVANIMATION_H

#include "fRect.h"
#include <vector>

class UVAnimation
{
public:
	/**�R���X�g���N�^*/
	UVAnimation();
	/**�f�X�g���N�^*/
	~UVAnimation();

	/**
	 * �A�j���[�V�����̃f�[�^��ݒ肷��֐�
	 * @param [in] 
	 * @param [in] 
	 * @param [in] 
	 * @param [in] 
	 */
	void CreateAnimationData(int tuCount_, int tvCount_, const fRect moveUVval_, float changeFlameTime_);

	/**
	* �A�j���[�V�����̍X�V�֐�
	* @retval		true		�X�V����
	* @retval		false		�X�V���s
	*/
	bool UpData();

	/**
	 * �A�j���[�V�����f�[�^����ꍞ�ފ֐�
	 * @param [in] animeNum_		1��ނ̃A�j���[�V�����̖���
	 * @param [in] isReverse_		���]�A�j���[�V�����������邩�ǂ���
	 */
	void SetAnimetionData(int animeNum_, bool isReverse_);

	/**
	 * ��`���̎擾�֐�
	 * @return m_currntAnimeData.UV ���݂�UV
	 */
	fRect GetRect() const
	{
		return m_currntAnimeData.UV;
	}

#pragma region �����o�ϐ�
private:
#pragma region �A�j���[�V�����f�[�^�\����
	struct AnimationData
	{
		fRect	UV;
		float	changeUVFlame;

		AnimationData(const fRect& texUV_, float flame) :
		UV(texUV_),
		changeUVFlame(flame)
		{}
	};
#pragma endregion
	std::vector<AnimationData>	m_animeData;
	std::vector<int>			m_animeNumber;
	AnimationData				m_currntAnimeData;
	bool						m_isReverse;
	int							m_currentFlame;
#pragma endregion
};

#endif // !UVANIMATION_H