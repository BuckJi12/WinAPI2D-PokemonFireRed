#include "framework.h"
#include "CSceneBattle.h"

#include "CImageObject.h"
#include "CGameObject.h"

// Enviorment
#include "CPlayerFloor.h"
#include "COpponentFloor.h"

// Player
#include "CPlayerThrowBall.h"

CSceneBattle::CSceneBattle()
{
	m_pImageBackGround		= nullptr;
	m_pImagePlayerFloor		= nullptr;
	m_pImageOpponentFloor	= nullptr;
	m_pImageNoramUI			= nullptr;
	m_pImagePlayerThrow		= nullptr;

	m_time					= 0;
}

CSceneBattle::~CSceneBattle()
{
}

void CSceneBattle::EnterInit()
{
	m_pImagePlayerFloor->SetPos(1600, 335);

	m_pImagePlayerThrow->Setting(Vector(1802, 272));

	m_pImageOpponentFloor->SetPos(-1025, 125);
	BATTLE->GetOpponentCurPokemon()->SetAnimation();
	m_pImageOpponentFloor->SetChild(BATTLE->GetOpponentCurPokemon());

	AddGameObject(m_pImagePlayerFloor);
	AddGameObject(m_pImageOpponentFloor);

	AddGameObject(m_pImagePlayerThrow);
	AddGameObject(BATTLE->GetOpponentCurPokemon());
	AddGameObject(m_pImageNoramUI);
}

void CSceneBattle::TakeOutPlayerPokemon()
{
	m_pImagePlayerThrow->Play();
	m_time += DT;
	if (m_time >= 3)
	{
		BATTLE->GetPlayerCurPokemon()->SetPos(200, 310);
		BATTLE->GetPlayerCurPokemon()->SetAnimation();
		AddGameObject(BATTLE->GetPlayerCurPokemon());
		BATTLE->ChooseAction(PlayerAction::ChooseAction);
		m_time = 0;
	}
}

void CSceneBattle::Init()
{
	// 배경
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"BackGround", L"Image\\Battle\\BackGround.png"));
	m_pImageBackGround->SetPos(0, 0);
	AddGameObject(m_pImageBackGround);

	// 환경
	m_pImagePlayerFloor		= new CPlayerFloor;
	m_pImageOpponentFloor	= new COpponentFloor;

	// 플레이어
	m_pImagePlayerThrow		= new CPlayerThrowBall;

	//TODO: 별도 텍스트 박스로 만들기
	m_pImageNoramUI = new CImageObject;
	m_pImageNoramUI->SetPos(0, 400);
	m_pImageNoramUI->SetImage(RESOURCE->LoadImg(L"TextBox", L"Image\\Battle\\TextBox.png"));
}

void CSceneBattle::Enter()
{
	CAMERA->FadeIn(3.0f);
	BATTLE->BattleInit();
	EnterInit();
}

void CSceneBattle::Update()
{
	if (BUTTONDOWN(VK_F4))
	{
		EnterInit();
	}

	if (BUTTONDOWN(VK_ESCAPE))
	{
		DELAYCHANGESCENE(GroupScene::PrevScene, 3);
	}

	switch (BATTLE->GetCurAction())
	{
	case PlayerAction::Enter:
		if (BUTTONDOWN(VK_SPACE))
		{
			BATTLE->ChooseAction(PlayerAction::PlayerReady);
		}
		break;
	case PlayerAction::PlayerReady:
		TakeOutPlayerPokemon();
		break;
	case PlayerAction::ChooseAction:
		break;
	default:
		break;
	}
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
