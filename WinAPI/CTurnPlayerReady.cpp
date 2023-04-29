#include "framework.h"
#include "CTurnPlayerReady.h"

CTurnPlayerReady::CTurnPlayerReady(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_time = 0;
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
}

void CTurnPlayerReady::Update()
{
	m_time += DT;
	if (m_time >= 3)
	{
		BATTLE->GetPlayerCurPokemon()->SetPos(200, 310);
		BATTLE->GetPlayerCurPokemon()->SetAnimation();
		m_battleScene->AddObjectThisScene(BATTLE->GetPlayerCurPokemon());
		BATTLE->ChooseAction(PlayerAction::ChooseAction);
		m_time = 0;
	}
}

void CTurnPlayerReady::Exit()
{
}

void CTurnPlayerReady::Release()
{
}
