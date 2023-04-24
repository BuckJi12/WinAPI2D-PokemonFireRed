#include "framework.h"
#include "CBattleManager.h"

#include "CPokemon.h"
#include "CCharmander.h"

float typeDamage[18][18] // ȿ�� ���� 2.0 �Ϲ� 1.0 ȿ���� ������ 0.5 ȿ�� ���� 0.0
{// none �븻  ��   ��   ����  Ǯ  ���� ����  ��   ��  ���� ������ ���� ���� ����Ʈ ��   ��   ��ö
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, // NONE
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 0.0, 1.0, 1.0, 0.5, // NORMAL
	1.0, 1.0, 0.5, 0.5, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 2.0, // FIRE
	1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0, // WATER
	1.0, 1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, // ELECTRIC
	1.0, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 0.5, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 0.5, // GRASS
	1.0, 1.0, 0.5, 0.5, 1.0, 2.0, 0.5, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, // ICE
	1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.5, 0.5, 0.5, 2.0, 0.0, 1.0, 2.0, 2.0, // FIGHT
	1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 0.0, // POISON
	1.0, 1.0, 2.0, 1.0, 2.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 2.0, // GROUND
	1.0, 1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 0.5, // FLYING
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 0.0, 0.5, // PSYCHIC
	1.0, 1.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.5, 0.5, 1.0, 0.5, 2.0, 1.0, 1.0, 0.5, 1.0, 2.0, 0.5, // BUG
	1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, // ROCK
	1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, // GHOST
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, // DRAGON
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, // DARK
	1.0, 1.0, 0.5, 0.5, 0.5, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, // STEEL
};

CBattleManager::CBattleManager()
{
	m_pPlayerCurPokemon = nullptr;
	m_pOppoentCurPokemon = nullptr;
	m_curAction = PlayerAction::Wait;
	m_curFirstAttack = FirstAttack::Player;

	catchRate = 1;
	isCatching = false;
}

CBattleManager::~CBattleManager()
{
}

void CBattleManager::BattleInit()
{
	m_pPlayerCurPokemon = PLAYER->GetPlayerFirstPokemon();
	m_pOppoentCurPokemon = new CCharmander(5);
}

void CBattleManager::ChooseAction(PlayerAction action)
{
	m_curAction = action;
}

void CBattleManager::CheckFirstAttack()
{
	if (m_pPlayerCurPokemon->GetPokemonStat().speed >= m_pOppoentCurPokemon->GetPokemonStat().speed)
	{
		m_curFirstAttack = FirstAttack::Player;
	}
	else
	{
		m_curFirstAttack = FirstAttack::Oppoent;
	}
}

void CBattleManager::PlayerUseMove()
{
	// TODO: ����
}

void CBattleManager::OppoentUseMove()
{
	// TODO: ����
}

int CBattleManager::CalculateDamage(CPokemon* attacker, CPokemon* victim, CMove move)
{
	// TODO: ����
	return 0;
}

int CBattleManager::CalculateCatchRate()
{
	float fNum;

	fNum = ((((3 * m_pOppoentCurPokemon->GetPokemonStat().maxHp) - (2 * m_pOppoentCurPokemon->GetPokemonStat().curHp))
		* m_pOppoentCurPokemon->GetPokemonInfo().rate * 1/*TODO: �� Ȯ��*/) / (3 * m_pOppoentCurPokemon->GetPokemonStat().maxHp));
	catchRate = 65535 * pow((fNum / 255), 1.0 / 4) + 65535;

	return catchRate;
}

void CBattleManager::PokemonChanage(int index)
{
	// TODO: ����
}

bool CBattleManager::TryPokemonCatch()
{
	if (!isCatching)
	{
		isCatching = true;
		float timer = 0;
		srand(time(NULL));
		int number1 = rand() % 65535 + 1;
		int number2 = rand() % 65535 + 1;
		int number3 = rand() % 65535 + 1;
		int number4 = rand() % 65535 + 1;

		while (true)
		{
			timer += DT;
			if (timer > 3)
			{
				if (catchRate < number1)
				{
					isCatching = false;
					return false;
				}
			}

			if (timer > 6)
			{
				if (catchRate < number2)
				{
					isCatching = false;
					return false;
				}
			}

			if (timer > 9)
			{
				if (catchRate < number3)
				{
					isCatching = false;
					return false;
				}
			}

			if (timer > 12)
			{
				if (catchRate <= number4)
				{
					isCatching = false;
					return false;
				}
				else
				{
					isCatching = false;
					return true;
				}
			}
		}
	}

	return false;
}

bool CBattleManager::CheckBattleAble()
{
	//TODO: ����
	return false;
}