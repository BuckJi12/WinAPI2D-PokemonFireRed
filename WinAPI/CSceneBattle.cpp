#include "framework.h"
#include "CSceneBattle.h"

#include "CImageObject.h"
#include "CGameObject.h"

// Enviorment
#include "CPlayerFloor.h"
#include "COpponentFloor.h"

// Player
#include "CPlayerThrowBall.h"

// Turn
#include "CTurnEnter.h"

CSceneBattle::CSceneBattle()
{
	m_curTurn = nullptr;

	m_pImageBackGround		= nullptr;
}

CSceneBattle::~CSceneBattle()
{
}

void CSceneBattle::TakeOutPlayerPokemon()
{
	/*m_pImagePlayerThrow->Play();
	m_time += DT;
	if (m_time >= 3)
	{
		BATTLE->GetPlayerCurPokemon()->SetPos(200, 310);
		BATTLE->GetPlayerCurPokemon()->SetAnimation();
		AddGameObject(BATTLE->GetPlayerCurPokemon());
		BATTLE->ChooseAction(PlayerAction::ChooseAction);
		m_time = 0;
	}*/
}

void CSceneBattle::AddObjectThisScene(CGameObject* object)
{
	AddGameObject(object);
}

void CSceneBattle::ChangeTurn(PlayerAction action)
{
	m_curTurn->Exit();
	m_curTurn = m_mapTurns[action];
	m_curTurn->Enter();
}

void CSceneBattle::Init()
{
	// ¹è°æ
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"BackGround", L"Image\\Battle\\BackGround.png"));
	m_pImageBackGround->SetPos(0, 0);
	AddGameObject(m_pImageBackGround);

	m_mapTurns.insert(make_pair(PlayerAction::Enter, new CTurnEnter(this)));

	m_mapTurns[PlayerAction::Enter]->Init();

	m_curTurn = m_mapTurns[PlayerAction::Enter];
}

void CSceneBattle::Enter()
{
	CAMERA->FadeIn(3.0f);
	BATTLE->BattleInit();
	m_curTurn->Enter();
}

void CSceneBattle::Update()
{
	m_curTurn->Update();
	/*
	switch (BATTLE->GetCurAction())
	{
	case PlayerAction::Enter:
		break;
	case PlayerAction::PlayerReady:
		TakeOutPlayerPokemon();
		break;
	case PlayerAction::ChooseAction:
		break;
	default:
		break;
	}*/
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
