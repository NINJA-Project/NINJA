/**
 * @file	Library.cpp
 * @breif	ライブラリ全体の統括クラス実装
 * @author	shibata
 */

#include "Library.h"
#include "Library\GraphicsDevice.h"
#include "Library\InputDvice.h"
#include "Library\SoundDevice.h"
#include "Library\InputManager.h"
#include "Library\Window.h"
#include "Library\TextureFileManager.h"
#include "Library\VertexManager.h"
#include "Library\SoundFileManager.h"
#include "Library\XFileManager.h"
#include "Library\Font.h"
#include "Library\CommoSystem.h"
#include "Library\Vector2D.h"


Library::Library() :
m_pGraphicsDevice(nullptr),
m_pInputDevice(nullptr),
m_pSoundDevice(nullptr),
m_pInputManager(nullptr),
m_pWindow(NULL),
m_pTextureFileManager(NULL),
m_pSoundFileManager(NULL),
m_pXFileManager(NULL)
{

}

Library::~Library()
{
	SafeDelete(m_pWindow);
	SafeDelete(m_pXFileManager);
	SafeDelete(m_pInputManager);
	SafeDelete(m_pSoundFileManager);
	SafeDelete(m_pTextureFileManager);
	ReleaseAllVirtices();
	m_pSoundDevice->DestroyInstance();
	m_pInputDevice->DestroyInstance();
	m_pGraphicsDevice->DestroyInstance();
}

void Library::Initialize(const char* pWindowName_, int clientWidth_, int clientHeight_, bool isFullScreen_)
{
	m_pWindow = New Window;
	m_pWindow->Create(pWindowName_, clientWidth_, clientHeight_, isFullScreen_);

	m_pGraphicsDevice = &GraphicsDevice::GetInstance();
	m_pGraphicsDevice->Initialize(m_pWindow->GetHwnd(), clientWidth_, clientHeight_, isFullScreen_);

	m_pInputDevice = &InputDevice::GetInstance();
	m_pInputDevice->Initialize(m_pWindow->GetHwnd());

	m_pSoundDevice = &SoundDevice::GetInstance();
	m_pSoundDevice->Initialize(m_pWindow->GetHwnd());

	m_pInputManager			= New InputManager;
	m_pTextureFileManager	= New TextureFileManager;
	m_pXFileManager			= New XFileManager;
	m_pSoundFileManager		= New SoundFileManager;
}

//---------------------Windowクラスのパブリック関数----------------------------------
bool Library::Update()
{
	bool isUpdate = m_pWindow->Update();
	return isUpdate;
}

int Library::GetWinWidth()
{
	return m_pWindow->GetWidth();
}

int Library::GetWinHeight()
{
	return m_pWindow->GetHeight();
}

//---------------------DirectX9クラスのパブリック関数--------------------------------
void Library::SetFVF(const DWORD& fvf_)
{
	m_pGraphicsDevice->SetFVF(fvf_);
}

void Library::RenderStarting()
{
	m_pGraphicsDevice->RenderStarting();
}

void Library::RenderEnding()
{
	m_pGraphicsDevice->RenderEnding();
}

LPDIRECT3DDEVICE9 Library::GetDevice()
{
	return m_pGraphicsDevice->GetDevice();
}

//---------------------InputManagerクラスのパブリック関数----------------------------
void Library::UpdateDI()
{
	m_pInputManager->UpdateDI();
}

void Library::UpdateKey()
{
	m_pInputManager->UpdateKey();
}

KeyState Library::ChooseKey(int dik_)
{
	KeyState keyState = static_cast<KeyState>(m_pInputManager->ChooseKey(dik_));
	return keyState;
}

//---------------------TextureFileManagerクラスのパブリック関数----------------------
void Library::LoadTextureFile(int index_, const char* filePath_)
{
	m_pTextureFileManager->LoadTextureFile(index_, filePath_);
}

void Library::LoadTextuerMoreInfo(int index_, const char* filePath_, int alpha_, int red_, int green_, int blue_, bool isTwoPower_)
{
	m_pTextureFileManager->LoadTextuerMoreInfo(index_, filePath_, alpha_, red_, green_, blue_, isTwoPower_);
}

void Library::ReleaseAllTexture()
{
	m_pTextureFileManager->ReleaseAllTexture();
}

void Library::ReleaseTexture(int index_)
{
	m_pTextureFileManager->ReleaseTexture(index_);
}

//---------------------VerticesManagerクラスのパブリック関数-------------------------
void Library::SetTexSize(int loadIndex_, int drawIndex_, float width_, float height_, float maxTu_, float maxTv_, float minTu_, float minTv_, float depth_)
{
	m_pVertexManager.emplace_back(New VertexManager);
	m_pVertexManager[drawIndex_]->SetTexSize(loadIndex_, width_, height_, maxTu_, maxTv_, minTu_, minTv_, depth_);
}

void Library::DrawLeftTop(int loadIndex_, int drawIndex_, float posX_, float posY_)
{
	m_pVertexManager[drawIndex_]->DrawLeftTop(loadIndex_, posX_, posY_, m_pTextureFileManager->GetTextureFileData(loadIndex_));
}

void Library::DrawCenter(int loadIndex_, int drawIndex_, float posX_, float posY_)
{
	m_pVertexManager[drawIndex_]->DrawCenter(loadIndex_, posX_, posY_, m_pTextureFileManager->GetTextureFileData(loadIndex_));
}

void Library::SetColor(int loadIndex_, int drawIndex_, DWORD color_, int alpha_, int red_, int green_, int blue_)
{
	m_pVertexManager[drawIndex_]->SetColor(loadIndex_, color_, alpha_, red_, green_, blue_);
}

void Library::ReleaseAllVirtices()
{
	for (auto& itr : m_pVertexManager)
	{
		delete itr;
	}
}

void Library::ReleaseVirtices(int loadIndex_, int drawIndex_)
{
	m_pVertexManager[drawIndex_]->ReleaseVirtices(loadIndex_);
}

//---------------------SoundFileManagerクラスのパブリック関数--------------------------
void Library::LoadSoundFile(int index_, const char* filePath_)
{
	m_pSoundFileManager->LoadSoundFile(index_, filePath_);
}

void Library::SoundState(int index_, SoundMode soundMode_)
{
	m_pSoundFileManager->SoundState(index_, static_cast<SoundFileManager::SoundMode>(soundMode_));
}

void Library::ReleaseAllSoundData()
{
	m_pSoundFileManager->ReleaseAllSoundData();
}

void Library::ReleaseSoundData(int index_)
{
	m_pSoundFileManager->ReleaseSoundData(index_);
}

//---------------------XFileManagerクラスのパブリック関数------------------------------
void Library::LoadXFile(int index_, const char* filePath_)
{
	m_pXFileManager->LoadXFile(index_, filePath_);
}

void Library::DrawXFile(int index_)
{
	m_pXFileManager->DrawXFile(index_);
}

void Library::ReleaseAllXFile()
{
	m_pXFileManager->ReleaseAllXFile();
}

void Library::ReleaseXFile(int index_)
{
	m_pXFileManager->ReleaseXFile(index_);
}

//---------------------Fontクラスのパブリック関数----------------------------------------
void Library::DrawFont(const char* pString_, float posX_, float posY_, DWORD format_, int red_, int green_, int blue_)
{
	Font font;
	font.DrawFont(pString_, Vector2D(posX_, posY_), format_, red_, green_, blue_);
}

void Library::DrawFont(int width_, int height_, const char* pString_, float posX_, float posY_, DWORD format_, int red_, int green_, int blue_)
{
	Font font(width_, height_);
	font.DrawFont(pString_, Vector2D(posX_, posY_), format_, red_, green_, blue_);
}