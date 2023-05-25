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
		if (!m_playerAttacked)
		{
			//�÷��̾� ����
			m_battleScene->GetTextBox()->SetText(L"����! " + BATTLE->GetPlayerCurPokemon()->GetPokemonInfo().name +
			L" " + BATTLE->GetCurMove()->GetMoveStat().name + L"\n");
			if (m_timer > 2)
			{
				BATTLE->PlayerAttack();
				//TODO: ȿ�� �ۼ�
				if (m_timer > 4)
				{
					m_playerAttacked = true;
					if (BATTLE->GetBattleSituation() == BattleSituation::Opponet_CanNot_Battle)
					{
						//��Ʋ �¸�
						BATTLE->SetBattleResult(BattleResult::Win);
						m_battleScene->ChangeTurn(PlayerAction::Result);
					}
				}
			}
		}
		if (m_timer > 6 && !m_OpponentAttacked)
		{
			//��� ����
			if (m_timer > 8)
			{
				//TODO: ȿ�� �ۼ�
				BATTLE->OppoentUseMove();
				if (m_timer > 10)
				{
					m_OpponentAttacked = true;
					if (BATTLE->GetBattleSituation() == BattleSituation::Player_CanNot_Battle)
					{
						//�÷��̾� �й�
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
			}
		}
		break;
	case FirstAttack::Oppoent:
		if (!m_OpponentAttacked)
		{
			//��� ����
			if (m_timer > 2)
			{
				//TODO: ȿ�� �ۼ�
				BATTLE->OppoentUseMove();
				if (m_timer > 4)
				{
					m_OpponentAttacked = true;
					if (BATTLE->GetBattleSituation() == BattleSituation::Player_CanNot_Battle)
					{
						//�÷��̾� �й�
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
			}
		}

		if (m_timer > 6 && !m_playerAttacked)
		{
			//�÷��̾� ����
			m_battleScene->GetTextBox()->SetText(L"����! " + BATTLE->GetPlayerCurPokemon()->GetPokemonInfo().name +
				L" " + BATTLE->GetCurMove()->GetMoveStat().name + L"\n");
			if (m_timer > 8)
			{
				BATTLE->PlayerAttack();
				//TODO: ȿ�� �ۼ�
				if (m_timer > 10)
				{
					m_playerAttacked = true;
					if (BATTLE->GetBattleSituation() == BattleSituation::Opponet_CanNot_Battle)
					{
						//��Ʋ �¸�
						BATTLE->SetBattleResult(BattleResult::Win);
						m_battleScene->ChangeTurn(PlayerAction::Result);
					}
				}
			}
		}
		break;
	case FirstAttack::OnlyOpponent:
		m_playerAttacked = true;
		if (!m_OpponentAttacked)
		{
			// ��� ���� ���
			if (m_timer > 2)
			{
				BATTLE->OppoentUseMove();
				//TODO: ȿ�� �ۼ�
				if (m_timer > 4)
				{
					m_OpponentAttacked = true;
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
			}
		}
		break;
	}

	if (m_playerAttacked && m_OpponentAttacked)
	{
		BATTLE->CheckBattleAble();
		// �� ���ϸ� ��� ��Ʋ�� ������ �� �÷��̾� �ൿ���������� �̵�
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
