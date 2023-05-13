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
			//TODO: �÷��̾� ����
			m_playerAttacked = true;
			BATTLE->PlayerAttack();
			if (BATTLE->GetBattleSituation() == BattleSituation::Opponet_CanNot_Battle)
			{
				//TODO: ��Ʋ �¸�
			}
		}
		if (m_timer > 4 && !m_OpponentAttacked)
		{
			//TODO: ��� ����
			m_OpponentAttacked = true;
			BATTLE->OppoentUseMove();
			if (BATTLE->GetBattleSituation() == BattleSituation::Player_CanNot_Battle)
			{
				//TODO: �÷��̾� ���ϸ� ��ü �Ǵ� �÷��̾� �й�
			}
		}
		break;
	case FirstAttack::Oppoent:
		if (m_timer > 1 && !m_OpponentAttacked)
		{
			//TODO: �÷��̾� ����
			m_OpponentAttacked = true;
			BATTLE->OppoentUseMove();
			if (BATTLE->GetBattleSituation() == BattleSituation::Player_CanNot_Battle)
			{
				//TODO: �÷��̾� ���ϸ� ��ü �Ǵ� �÷��̾� �й�
			}
		}
		if (m_timer > 4 && !m_playerAttacked)
		{
			//TODO: ��� ����
			m_playerAttacked = true;
			BATTLE->PlayerAttack();
			if (BATTLE->GetBattleSituation() == BattleSituation::Opponet_CanNot_Battle)
			{
				//TODO: ��Ʋ �¸�
			}
		}
		break;
	case FirstAttack::OnlyOpponent:
		m_playerAttacked = true;
		if (m_timer > 1 && !m_OpponentAttacked)
		{
			//TODO: ��� ����
			m_OpponentAttacked = true;
			BATTLE->OppoentUseMove();
			if (BATTLE->GetBattleSituation() == BattleSituation::Player_CanNot_Battle)
			{
				//TODO: �÷��̾� ���ϸ� ��ü �Ǵ� �÷��̾� �й�
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
