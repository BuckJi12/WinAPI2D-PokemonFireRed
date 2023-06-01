#include "framework.h"
#include "CTurnBattle.h"

CTurnBattle::CTurnBattle(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_timer				= 0;
	m_playerAttacked	= false;
	m_OpponentAttacked	= false;
	m_checkPlayer		= false;
	m_checkOpponent		= false;
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
			//�÷��̾� ��� ��� ���
			m_battleScene->GetTextBox()->SetText(L"����! " + BATTLE->GetPlayerCurPokemon()->GetPokemonInfo().name +
			L" " + BATTLE->GetCurMove()->GetMoveStat().name + L"\n");
				if (m_timer > 3)
				{
					//TODO: ȿ�� �ۼ� ex ȿ���� �����ߴ� ��
					BATTLE->PlayerAttack();
					OutPutMoveResult(BATTLE->GetMoveResult());
					BATTLE->GetOpponentCurPokemon()->HitAnimation();
					RESOURCE->GetEffect(BATTLE->GetCurMove()->GetType())->SetPos(625, 155);
					RESOURCE->GetEffect(BATTLE->GetCurMove()->GetType())->Play();
					SOUND->Play(SOUND->GetMoveEffect(BATTLE->GetCurMove()->GetType()), 0.5f);
					m_playerAttacked = true;
				}
		}

		if (m_timer > 6 && !m_checkOpponent)
		{
			m_checkOpponent = true;
			if (BATTLE->GetBattleSituation() == BattleSituation::Opponet_CanNot_Battle)
			{
				//��Ʋ �¸�
				m_battleScene->GetTextBox()->SetText(BATTLE->GetOpponentCurPokemon()->GetPokemonInfo().name + L"��(��) " +
					L" " + L"��������\n");
				BATTLE->GetOpponentCurPokemon()->SetPos(1000, 1000);
				SOUND->Play(SOUND->GetSpecialSound(SpecialSound::Victory), 0.5f);
				BATTLE->SetBattleResult(BattleResult::Win);
				m_battleScene->ChangeTurn(PlayerAction::Result);
			}
		}

		if (m_timer > 9 && !m_OpponentAttacked)
		{
			//��� ��� ��� ���
			m_battleScene->GetTextBox()->SetText(BATTLE->GetOpponentCurPokemon()->GetPokemonInfo().name + L"��(��) " +
				L" " + BATTLE->GetCurOpponentMove()->GetMoveStat().name + L" ����ߴ�! \n");
			if (m_timer > 12)
			{
				//TODO: ȿ�� �ۼ� ex ȿ���� �����ߴ� ��
				BATTLE->OppoentUseMove();
				OutPutMoveResult(BATTLE->GetMoveResult());
				BATTLE->GetPlayerCurPokemon()->HitAnimation();
				RESOURCE->GetEffect(BATTLE->GetCurOpponentMove()->GetType())->SetPos(200, 310);
				RESOURCE->GetEffect(BATTLE->GetCurOpponentMove()->GetType())->Play();
				SOUND->Play(SOUND->GetMoveEffect(BATTLE->GetCurOpponentMove()->GetType()), 0.5f);
				m_OpponentAttacked = true;
			}		
		}

		if (m_timer > 15 && !m_checkPlayer)
		{
			m_checkPlayer = true;
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
		break;
	case FirstAttack::Oppoent:
		if (!m_OpponentAttacked)
		{
			//��� ��� ��� ���
			m_battleScene->GetTextBox()->SetText(BATTLE->GetOpponentCurPokemon()->GetPokemonInfo().name + L"��(��) " +
				L" " + BATTLE->GetCurOpponentMove()->GetMoveStat().name + L" ����ߴ�! \n");
			if (m_timer > 3)
			{
				//TODO: ȿ�� �ۼ� ex ȿ���� �����ߴ� ��
				BATTLE->OppoentUseMove();
				OutPutMoveResult(BATTLE->GetMoveResult());
				BATTLE->GetPlayerCurPokemon()->HitAnimation();
				RESOURCE->GetEffect(BATTLE->GetCurOpponentMove()->GetType())->SetPos(200, 310);
				RESOURCE->GetEffect(BATTLE->GetCurOpponentMove()->GetType())->Play();
				SOUND->Play(SOUND->GetMoveEffect(BATTLE->GetCurOpponentMove()->GetType()), 0.5f);
				m_OpponentAttacked = true;
			}
		}

		if (m_timer > 6 && !m_checkPlayer)
		{
			m_checkPlayer = true;
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

		if (m_timer > 9 && !m_playerAttacked)
		{
			//�÷��̾� ��� ��� ���
			m_battleScene->GetTextBox()->SetText(L"����! " + BATTLE->GetPlayerCurPokemon()->GetPokemonInfo().name +
				L" " + BATTLE->GetCurMove()->GetMoveStat().name + L"\n");
			if (m_timer > 12)
			{
				//TODO: ȿ�� �ۼ� ex ȿ���� �����ߴ� ��
				BATTLE->PlayerAttack();
				OutPutMoveResult(BATTLE->GetMoveResult());
				BATTLE->GetOpponentCurPokemon()->HitAnimation();
				RESOURCE->GetEffect(BATTLE->GetCurMove()->GetType())->SetPos(625, 155);
				RESOURCE->GetEffect(BATTLE->GetCurMove()->GetType())->Play();
				SOUND->Play(SOUND->GetMoveEffect(BATTLE->GetCurMove()->GetType()), 0.5f);
				m_playerAttacked = true;
			}
		}

		if (m_timer > 15 && !m_checkOpponent)
		{
			m_checkOpponent = true;
			if (BATTLE->GetBattleSituation() == BattleSituation::Opponet_CanNot_Battle)
			{
				//��Ʋ �¸�
				m_battleScene->GetTextBox()->SetText(BATTLE->GetOpponentCurPokemon()->GetPokemonInfo().name + L"��(��) " +
					L" " + L"��������\n");
				SOUND->Play(SOUND->GetSpecialSound(SpecialSound::Victory), 0.5f);
				BATTLE->GetOpponentCurPokemon()->SetPos(1000, 1000);
				BATTLE->SetBattleResult(BattleResult::Win);
				m_battleScene->ChangeTurn(PlayerAction::Result);
			}
		}
		break;
	case FirstAttack::OnlyOpponent:
		m_playerAttacked = true;
		m_checkOpponent = true;
		if (!m_OpponentAttacked)
		{
			//��� ��� ��� ���
			m_battleScene->GetTextBox()->SetText(BATTLE->GetOpponentCurPokemon()->GetPokemonInfo().name + L"��(��) " +
				L" " + BATTLE->GetCurOpponentMove()->GetMoveStat().name + L" ����ߴ�! \n");
			if (m_timer > 3)
			{
				//TODO: ȿ�� �ۼ� ex ȿ���� �����ߴ� ��
				BATTLE->OppoentUseMove();
				OutPutMoveResult(BATTLE->GetMoveResult());
				BATTLE->GetPlayerCurPokemon()->HitAnimation();
				RESOURCE->GetEffect(BATTLE->GetCurOpponentMove()->GetType())->SetPos(200, 310);
				RESOURCE->GetEffect(BATTLE->GetCurOpponentMove()->GetType())->Play();
				SOUND->Play(SOUND->GetMoveEffect(BATTLE->GetCurOpponentMove()->GetType()), 0.5f);
				m_OpponentAttacked = true;
			}
		}
		if (m_timer > 6 && !m_checkPlayer)
		{
			m_checkPlayer = true;
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
		break;
	}

	if (m_playerAttacked && m_OpponentAttacked && m_checkOpponent && m_checkPlayer)
	{
		BATTLE->CheckBattleAble();
		// �� ���ϸ� ��� ��Ʋ�� ������ �� �÷��̾� �ൿ���������� �̵�
		if (BATTLE->GetBattleSituation() == BattleSituation::BothSide_Can_Battle)
		{
			m_battleScene->ChangeTurn(PlayerAction::ChooseAction);
		}
	}
}

void CTurnBattle::OutPutMoveResult(MoveResult result)
{
	switch (result)
	{
	case MoveResult::Normal:
		m_battleScene->GetTextBox()->SetText(L"ȿ���� ����ߴ�!\n");
		break;
	case MoveResult::Good:
		m_battleScene->GetTextBox()->SetText(L"ȿ���� �����ߴ�!!!!\n");
		break;
	case MoveResult::Bad:
		m_battleScene->GetTextBox()->SetText(L"ȿ���� ���ο���...\n");
		break;
	case MoveResult::Nothing:
		m_battleScene->GetTextBox()->SetText(L"�ƹ��ϵ� ������......\n");
		break;
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
	m_checkPlayer = false;
	m_checkOpponent = false;
	BATTLE->OpponentSelectMove();
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
