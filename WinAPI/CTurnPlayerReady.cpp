#include "framework.h"
#include "CTurnPlayerReady.h"

#include "CBallObject.h"

CTurnPlayerReady::CTurnPlayerReady(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_time = 0;
	m_pBallObject = nullptr;
}

CTurnPlayerReady::~CTurnPlayerReady()
{
}

void CTurnPlayerReady::Init()
{
	m_pBallObject = new CBallObject;
}

void CTurnPlayerReady::Enter()
{
	m_time = 0;
	m_pBallObject->SetMode(BallMode::TakeOut);
	m_pBallObject->SetPos(50, 300);
	//m_pBallObject->SetMode(BallMode::Catch);
	//m_pBallObject->SetPos(50, 300);
	//m_pBallObject->SetTarget(BATTLE->GetOpponentCurPokemon());
	m_battleScene->AddObjectThisScene(m_pBallObject);
}

void CTurnPlayerReady::Update()
{
	m_time += DT;
	if (m_time >= 2)
	{
		BATTLE->GetPlayerCurPokemon()->SetPos(200, 310);
		BATTLE->GetPlayerCurPokemon()->SetAnimation();
		m_battleScene->AddObjectThisScene(BATTLE->GetPlayerCurPokemon());
		BATTLE->ChooseAction(PlayerAction::ChooseAction);
		m_time = 0;
	}

	if (m_pBallObject->m_vecPos.y > 385)
		DELETEOBJECT(m_pBallObject);
}

void CTurnPlayerReady::Exit()
{
}

void CTurnPlayerReady::Release()
{
	delete m_pBallObject;
}
