#include "framework.h"
#include "CTurnPlayerReady.h"

#include "CBallObject.h"
#include "CPlayerStatUI.h"

CTurnPlayerReady::CTurnPlayerReady(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pBallObject			= nullptr;

	m_time					= 0;
	m_isUICreated			= false;
}

CTurnPlayerReady::~CTurnPlayerReady()
{
}

void CTurnPlayerReady::Init()
{
}

void CTurnPlayerReady::Enter()
{
	m_time = 0;
	m_pBallObject = new CBallObject;
	m_pBallObject->SetMode(BallMode::TakeOut);
	m_pBallObject->SetPos(50, 300);
	//m_pBallObject->SetMode(BallMode::Catch);
	//m_pBallObject->SetPos(50, 300);
	//m_pBallObject->SetTarget(BATTLE->GetOpponentCurPokemon());
	BATTLE->GetPlayerCurPokemon()->AddObserver(m_battleScene->GetPlayerUI());
	m_battleScene->GetPlayerUI()->SetPokemon(BATTLE->GetPlayerCurPokemon());
	m_battleScene->GetPlayerUI()->SetPos(1600, 266);

	m_battleScene->AddObjectThisScene(m_pBallObject);
	if (!m_isUICreated)
	{
		m_battleScene->AddObjectThisScene(m_battleScene->GetPlayerUI());
		m_isUICreated = true;
	}
}

void CTurnPlayerReady::Update()
{
	m_time += DT;
	if (m_time >= 2)
	{
		BATTLE->GetPlayerCurPokemon()->SetPos(200, 310);
		BATTLE->GetPlayerCurPokemon()->SetAnimation();
		m_battleScene->ChangeTurn(PlayerAction::ChooseAction);
		m_time = 0;
	}

	if (m_pBallObject->m_vecPos.y > 385)
		DELETEOBJECT(m_pBallObject);
}

void CTurnPlayerReady::Exit()
{
	BATTLE->GetOpponentCurPokemon()->RemoveObserver(m_battleScene->GetPlayerUI());
}

void CTurnPlayerReady::Release()
{
	DELETEOBJECT(m_pBallObject);
}
