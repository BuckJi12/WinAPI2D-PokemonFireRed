#include "framework.h"
#include "CTurnBattle.h"

CTurnBattle::CTurnBattle(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_timer				= 0;
	m_playerAttacked	= false;
	m_OpponentAttacked	= false;
}

CTurnBattle::~CTurnBattle()
{
}

void CTurnBattle::PokemonAttack()
{
	m_timer += DT;

	switch (BATTLE->GetFirstAttack())
	{
	case FirstAttack::Player:
		if (m_timer > 1 && !m_playerAttacked)
		{
			//플레이어 공격
			m_playerAttacked = true;
			BATTLE->PlayerAttack();
			if (BATTLE->GetBattleSituation() == BattleSituation::Opponet_CanNot_Battle)
			{
				//배틀 승리
				BATTLE->SetBattleResult(BattleResult::Win);
				m_battleScene->ChangeTurn(PlayerAction::Result);
			}
		}
		if (m_timer > 3 && !m_OpponentAttacked)
		{
			//상대 공격
			m_OpponentAttacked = true;
			BATTLE->OppoentUseMove();
			if (BATTLE->GetBattleSituation() == BattleSituation::Player_CanNot_Battle)
			{
				//플레이어 패배
				if (BATTLE->PlayerCheckBattleAble())
				{
					m_battleScene->ChangeTurn(PlayerAction::Continue);
				}
				else
				{
					BATTLE->SetBattleResult(BattleResult::Lose);
					m_battleScene->ChangeTurn(PlayerAction::Result);
				}
			}
		}
		break;
	case FirstAttack::Oppoent:
		if (m_timer > 1 && !m_OpponentAttacked)
		{
			//상대 공격
			m_OpponentAttacked = true;
			BATTLE->OppoentUseMove();
			if (BATTLE->GetBattleSituation() == BattleSituation::Player_CanNot_Battle)
			{
				//플레이어 패배
				if (BATTLE->PlayerCheckBattleAble())
				{
					m_battleScene->ChangeTurn(PlayerAction::Continue);
				}
				else
				{
					BATTLE->SetBattleResult(BattleResult::Lose);
					m_battleScene->ChangeTurn(PlayerAction::Result);
				}
			}
		}
		if (m_timer > 3 && !m_playerAttacked)
		{
			// 플레이어 공격
			m_playerAttacked = true;
			BATTLE->PlayerAttack();
			if (BATTLE->GetBattleSituation() == BattleSituation::Opponet_CanNot_Battle)
			{
				BATTLE->SetBattleResult(BattleResult::Win);
				m_battleScene->ChangeTurn(PlayerAction::Result);
			}
		}
		break;
	case FirstAttack::OnlyOpponent:
		m_playerAttacked = true;
		if (m_timer > 1 && !m_OpponentAttacked)
		{
			// 상대 공격
			m_OpponentAttacked = true;
			BATTLE->OppoentUseMove();
			if (BATTLE->GetBattleSituation() == BattleSituation::Player_CanNot_Battle)
			{
				if (BATTLE->PlayerCheckBattleAble())
				{
					m_battleScene->ChangeTurn(PlayerAction::Continue);
				}
				else
				{
					BATTLE->SetBattleResult(BattleResult::Lose);
					m_battleScene->ChangeTurn(PlayerAction::Result);
				}
			}
		}
		break;
	}

	if (m_playerAttacked && m_OpponentAttacked)
	{
		BATTLE->CheckBattleAble();
		// 두 포켓몬 모두 배틀이 가능할 시 플레이어 행동선택턴으로 이동
		if (BATTLE->GetBattleSituation() == BattleSituation::BothSide_Can_Battle)
		{
			m_battleScene->ChangeTurn(PlayerAction::ChooseAction);
		}
	}
}

void CTurnBattle::Init()
{
}

void CTurnBattle::Enter()
{
	m_timer = 0;
	m_playerAttacked = false;
	m_OpponentAttacked = false;
}

void CTurnBattle::Update()
{
	PokemonAttack();
}

void CTurnBattle::Exit()
{
	m_timer = 0;
}

void CTurnBattle::Release()
{
}
