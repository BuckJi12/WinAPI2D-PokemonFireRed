#include "framework.h"
#include "CSceneBattle.h"

#include "CImageObject.h"
#include "CGameObject.h"

// Enviorment
#include "CPlayerFloor.h"

CSceneBattle::CSceneBattle()
{
	m_pImageBackGround = nullptr;
	m_pImagePlayerFloor = nullptr;
	m_pImageOpponentFloor = nullptr;
	m_pImageNoramUI = nullptr;
}

CSceneBattle::~CSceneBattle()
{
}

void CSceneBattle::EnterInit()
{
	m_pImagePlayerFloor->SetPos(1600, 335);

	AddGameObject(m_pImagePlayerFloor);
	AddGameObject(m_pImageNoramUI);
}

void CSceneBattle::Init()
{
	// 배경
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"BackGround", L"Image\\Battle\\BackGround.png"));
	m_pImageBackGround->SetPos(0, 0);
	AddGameObject(m_pImageBackGround);

	m_pImagePlayerFloor = new CPlayerFloor;

	m_pImageOpponentFloor = new CImageObject;
	m_pImageOpponentFloor->SetImage(RESOURCE->LoadImg(L"OppFloor", L"Image\\Battle\\OppFloor.png"));


	//TODO: 별도 텍스트 박스로 만들기
	m_pImageNoramUI = new CImageObject;
	m_pImageNoramUI->SetPos(0, 400);
	m_pImageNoramUI->SetImage(RESOURCE->LoadImg(L"TextBox", L"Image\\Battle\\TextBox.png"));
}

void CSceneBattle::Enter()
{
	CAMERA->FadeIn(3.0f);
	EnterInit();
}

void CSceneBattle::Update()
{
	
}

void CSceneBattle::Render()
{
}

void CSceneBattle::Exit()
{
}

void CSceneBattle::Release()
{
}
