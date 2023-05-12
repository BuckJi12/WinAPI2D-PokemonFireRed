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
#include "CTurnPlayerReady.h"
#include "CTurnChooseAction.h"
#include "CTurnChooseMove.h"

CSceneBattle::CSceneBattle()
{
	m_curTurn			= nullptr;
	m_pImageBackGround	= nullptr;
	m_pCursor			= nullptr;
}

CSceneBattle::~CSceneBattle()
{
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

CImageObject* CSceneBattle::GetCursor()
{
	return m_pCursor;
}

void CSceneBattle::Init()
{
	// ¹è°æ
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"BackGround", L"Image\\Battle\\BackGround.png"));
	m_pImageBackGround->SetPos(0, 0);
	AddGameObject(m_pImageBackGround);

	m_pCursor = new CImageObject;
	m_pCursor->SetImage(RESOURCE->LoadImg(L"Cursor", L"Image\\Battle\\Cursor.png"));
	m_pCursor->SetLayer(Layer::Environment3);
	m_pCursor->SetPos(1000, 1000);
	AddGameObject(m_pCursor);
	// ÅÏ
	m_mapTurns.insert(make_pair(PlayerAction::Enter, new CTurnEnter(this)));
	m_mapTurns.insert(make_pair(PlayerAction::PlayerReady, new CTurnPlayerReady(this)));
	m_mapTurns.insert(make_pair(PlayerAction::ChooseAction, new CTurnChooseAction(this)));
	m_mapTurns.insert(make_pair(PlayerAction::ChooseMove, new CTurnChooseMove(this)));

	m_mapTurns[PlayerAction::Enter]->Init();
	m_mapTurns[PlayerAction::PlayerReady]->Init();
	m_mapTurns[PlayerAction::ChooseAction]->Init();
	m_mapTurns[PlayerAction::ChooseMove]->Init();
}

void CSceneBattle::Enter()
{
	CAMERA->FadeIn(3.0f);
	BATTLE->BattleInit();
	m_curTurn = m_mapTurns[PlayerAction::Enter];
	m_curTurn->Enter();
}

void CSceneBattle::Update()
{
	m_curTurn->Update();
}

void CSceneBattle::Render()
{
}

void CSceneBattle::Exit()
{
}

void CSceneBattle::Release()
{
	for (pair<PlayerAction, CTurn*> turn : m_mapTurns)
	{
		turn.second->Release();
	}
}
