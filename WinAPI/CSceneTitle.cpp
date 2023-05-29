#include "framework.h"
#include "CSceneTitle.h"

#include "WinAPI.h"
#include "CRenderManager.h"
#include "CInputManager.h"
#include "CEventManager.h"
#include "CCameraManager.h"

#include "CTitleText.h"
#include "CTitleAnimation.h"

CSceneTitle::CSceneTitle()
{
	m_pImageBackGround		= nullptr;
	m_titleText				= nullptr;
	m_pSubTitle				= nullptr;
	m_pCharizardAni			= nullptr;
}

CSceneTitle::~CSceneTitle()
{
}

void CSceneTitle::Init()
{
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetPos(0,0);
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"TitleBackGround",L"Image\\UI\\TitleBackGround.png"));
	AddGameObject(m_pImageBackGround);

	m_titleText = new CTitleText;
	m_titleText->SetPos(400, 120);
	AddGameObject(m_titleText);

	m_pSubTitle = new CImageObject;
	m_pSubTitle->SetPos(650, 470);
	m_pSubTitle->SetImage(RESOURCE->LoadImg(L"SubTitle", L"Image\\UI\\SubTitle.png"));
	AddGameObject(m_pSubTitle);

	m_pCharizardAni = new CTitleAnimation;
	m_pCharizardAni->SetPos(400, 350);
	AddGameObject(m_pCharizardAni);
}

void CSceneTitle::Enter()
{
	CAMERA->FadeIn(0.25f);
}

void CSceneTitle::Update()
{
	if (BUTTONDOWN(VK_F1))
	{
		CHANGESCENE(GroupScene::TileTool);
	}
	if (BUTTONDOWN(VK_SPACE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::PlayerHome2F, 0.25f);
	}
}

void CSceneTitle::Render()
{
	RENDER->Text(L"press space to start",
		300,
		500,
		500,
		550,
		Color(255, 255, 255, 1.f),
		20.f);
}

void CSceneTitle::Exit()
{
}

void CSceneTitle::Release()
{
	DELETEOBJECT(m_pImageBackGround);
	DELETEOBJECT(m_titleText);
	DELETEOBJECT(m_pCharizardAni);
}
