#include "framework.h"
#include "CTurnResult.h"

CTurnResult::CTurnResult(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_timer = 0;
	m_gotReward = false;
}

CTurnResult::~CTurnResult()
{
}

void CTurnResult::GetReward()
{
	if (!m_gotReward)
	{
		m_gotReward = true;
		for (auto pokemon : PLAYER->GetPlayerPokemonList())
		{
			pokemon->AddExp(2500);
		}
	}

	//TODO: 플레이어 용돈 추가
}

void CTurnResult::BattleLose()
{
	//TODO: 텍스트 "플레이어는 눈 앞이 깜깜해졌다"
}

void CTurnResult::Init()
{
}

void CTurnResult::Enter()
{
	m_gotReward = false;
}

void CTurnResult::Update()
{
	switch (BATTLE->GetBattleResult())
	{
	case BattleResult::Win:
		GetReward();
		break;
	case BattleResult::Lose:
		BattleLose();
		break;
	}

	if (BUTTONDOWN(VK_SPACE))
	{
		Exit();
		SCENE->ChangePrevScene();
		GAME->SetRandomValue();
	}
}

void CTurnResult::Exit()
{
}

void CTurnResult::Release()
{
}
