#include "framework.h"
#include "CTurnPlayerReady.h"

#include "CBallObject.h"
#include "CPlayerStatUI.h"

CTurnPlayerReady::CTurnPlayerReady(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pBallObject			= nullptr;
	m_pImagePlayerStatUI	= nullptr;

	m_time = 0;
}

CTurnPlayerReady::~CTurnPlayerReady()
{
}

void CTurnPlayerReady::Init()
{
	m_pBallObject = new CBallObject;

	m_pImagePlayerStatUI = new CPlayerStatUI;
	m_pImagePlayerStatUI->Init();
}

void CTurnPlayerReady::Enter()
{
	m_time = 0;
	m_pBallObject->SetMode(BallMode::TakeOut);
	m_pBallObject->SetPos(50, 300);
	//m_pBallObject->SetMode(BallMode::Catch);
	//m_pBallObject->SetPos(50, 300);
	//m_pBallObject->SetTarget(BATTLE->GetOpponentCurPokemon());
	BATTLE->GetPlayerCurPokemon()->AddObserver(m_pImagePlayerStatUI);
	m_pImagePlayerStatUI->SetPokemon(BATTLE->GetPlayerCurPokemon());
	m_pImagePlayerStatUI->SetPos(1600, 266);

	m_battleScene->AddObjectThisScene(m_pBallObject);
	m_battleScene->AddObjectThisScene(m_pImagePlayerStatUI);
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
	DELETEOBJECT(m_pBallObject);
	DELETEOBJECT(m_pImagePlayerStatUI);
	BATTLE->GetOpponentCurPokemon()->RemoveObserver(m_pImagePlayerStatUI);
}
