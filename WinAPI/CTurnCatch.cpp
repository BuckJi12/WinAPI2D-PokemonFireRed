#include "framework.h"
#include "CTurnCatch.h"

#include "CBallObject.h"

CTurnCatch::CTurnCatch(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pBallObject	= nullptr;
	m_catchResult	= CatchResult::Fail1;
	m_timer			= 0;
	m_pokemonMoved	= false;
	m_catchComplete = false;
}

CTurnCatch::~CTurnCatch()
{
}

void CTurnCatch::Setting()
{
	m_catchResult	= BATTLE->TryPokemonCatch();
	m_timer			= 0;
	m_pokemonMoved	= false;
	m_catchComplete = false;
	m_pBallObject	= new CBallObject;
	m_pBallObject->SetMode(BallMode::Catch);
	m_pBallObject->SetLayer(Layer::Environment3);
	m_pBallObject->SetPos(50, 300);
	m_pBallObject->SetTarget(BATTLE->GetOpponentCurPokemon());

	m_battleScene->AddObjectThisScene(m_pBallObject);
}

void CTurnCatch::PokemonReset()
{
	DELETEOBJECT(m_pBallObject);
	BATTLE->GetOpponentCurPokemon()->SetPos(625, 155);
}

void CTurnCatch::CatchFail()
{
	BATTLE->SetFirstAttack(FirstAttack::OnlyOpponent);
	m_battleScene->ChangeTurn(PlayerAction::Battle);
}

void CTurnCatch::Init()
{
}

void CTurnCatch::Enter()
{
	Setting();
}

void CTurnCatch::Update()
{
	m_timer += DT;

	if (m_timer > 3 && !m_pokemonMoved)
	{
		m_pokemonMoved = true;
		BATTLE->GetOpponentCurPokemon()->SetPos(1000, 1000);
	}

	switch (m_catchResult)
	{
	case CatchResult::Fail1:
		if (m_timer > 5)
		{
			PokemonReset();
			CatchFail();
		}
		break;
	case CatchResult::Fail2:
		if (m_timer > 7)
		{
			PokemonReset();
			CatchFail();
		}
		break;
	case CatchResult::Fail3:
		if (m_timer > 9)
		{
			PokemonReset();
			CatchFail();
		}
		break;
	case CatchResult::Success:
		if (m_timer > 11 && !m_catchComplete)
		{
			DELETEOBJECT(m_pBallObject);
			m_catchComplete = true;
			CPokemon* pokemon = BATTLE->GetOpponentCurPokemon()->Clone();
			pokemon->Init();
			PLAYER->AddPokemonToPlayer(pokemon);
			BATTLE->SetBattleResult(BattleResult::Win);					// 배틀 승리
			m_battleScene->ChangeTurn(PlayerAction::Result);			// 결산으로 이동
		}
		break;
	}
}

void CTurnCatch::Exit()
{
}

void CTurnCatch::Release()
{
}
