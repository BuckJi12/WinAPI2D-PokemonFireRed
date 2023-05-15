#include "framework.h"
#include "CBattleManager.h"

#include "CPokemon.h"
#include "CCharmander.h"

float typeDamage[18][18] // 효과 좋음 2.0 일반 1.0 효과가 안좋음 0.5 효과 없음 0.0
{// none 노말  불   물   전기  풀  얼음 격투  독   땅  비행 에스퍼 벌레 바위 고스트 용   악   강철
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
	m_pPlayerCurPokemon		= nullptr;
	m_pOppoentCurPokemon	= nullptr;
	m_curAction				= PlayerAction::Enter;
	m_curFirstAttack		= FirstAttack::Player;
	m_playerCurInex			= 0;
	m_curBattleSituation	= BattleSituation::BothSide_Can_Battle;

	catchRate				= 1;
	isCatching				= false;
}

CBattleManager::~CBattleManager()
{
}

CPokemon* CBattleManager::GetPlayerCurPokemon()
{
	return m_pPlayerCurPokemon;
}

CPokemon* CBattleManager::GetOpponentCurPokemon()
{
	return m_pOppoentCurPokemon;
}

PlayerAction CBattleManager::GetCurAction()
{
	return m_curAction;
}

FirstAttack CBattleManager::GetFirstAttack()
{
	return m_curFirstAttack;
}

BattleSituation CBattleManager::GetBattleSituation()
{
	return m_curBattleSituation;
}

void CBattleManager::BattleInit()
{
	m_pPlayerCurPokemon = PLAYER->GetPlayerFirstPokemon();
	m_pOppoentCurPokemon = new CCharmander();
	m_pOppoentCurPokemon = POKEMON->FindPokemon(1);
	m_pOppoentCurPokemon->SetPokemonStat(5);
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

void CBattleManager::PlayerAttack()
{
	// TODO: 수정
	m_pPlayerCurPokemon->GetPokemonMoveList()[m_playerCurInex].UseMove(m_pOppoentCurPokemon);
	m_pOppoentCurPokemon->TakeDamage(CalculateDamage(m_pPlayerCurPokemon, m_pOppoentCurPokemon,
		m_pPlayerCurPokemon->GetPokemonMoveList()[m_playerCurInex]));
	CheckBattleAble();
}

void CBattleManager::OppoentUseMove()
{
	// TODO: 추후 수정이 필요함
	int random;
	while (true)
	{
		random = rand() % m_pOppoentCurPokemon->GetPokemonMoveList().size();
		if (m_pOppoentCurPokemon->GetPokemonMoveList()[random].GetMoveStat().curPP > 0)
			break;
	}

	m_pOppoentCurPokemon->GetPokemonMoveList()[random].UseMove(m_pPlayerCurPokemon);
	m_pPlayerCurPokemon->TakeDamage(CalculateDamage(m_pOppoentCurPokemon, m_pPlayerCurPokemon,
		m_pPlayerCurPokemon->GetPokemonMoveList()[random]));
	CheckBattleAble();
}

void CBattleManager::SelectMove(int index)
{
	m_playerCurInex = index;
}

int CBattleManager::CalculateDamage(CPokemon* attacker, CPokemon* victim, CMove move)
{
	int damage;
	if (move.GetKind() == MoveKind::Physics)
	{
		damage = ((((((attacker->GetPokemonStat().level * 2 / 5) + 2) * move.GetMoveStat().moveDamage *
			attacker->GetPokemonStat().attack / 50) / victim->GetPokemonStat().defence) * 1) + 2) *
			typeDamage[(int)move.GetType()][(int)victim->GetType(1)] * typeDamage[(int)move.GetType()][(int)victim->GetType(2)];
	}
	else
	{
		damage = ((((((attacker->GetPokemonStat().level * 2 / 5) + 2) * move.GetMoveStat().moveDamage *
			attacker->GetPokemonStat().specialAttack / 50) / victim->GetPokemonStat().specialDefence) * 1) + 2) *
			typeDamage[(int)move.GetType()][(int)victim->GetType(1)] * typeDamage[(int)move.GetType()][(int)victim->GetType(2)];
	}

	return damage;
}

int CBattleManager::CalculateCatchRate()
{
	float fNum;

	fNum = ((((3 * m_pOppoentCurPokemon->GetPokemonStat().maxHp) - (2 * m_pOppoentCurPokemon->GetPokemonStat().curHp))
		* m_pOppoentCurPokemon->GetPokemonInfo().rate * 1/*TODO: 볼 확률*/) / (3 * m_pOppoentCurPokemon->GetPokemonStat().maxHp));
	catchRate = 65535 * pow((fNum / 255), 1.0 / 4) + 65535;

	return catchRate;
}

void CBattleManager::PokemonChanage(int index)
{
	// TODO: 수정
	m_pPlayerCurPokemon = PLAYER->GetPlayerPokemonList()[index];
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

void CBattleManager::CheckBattleAble()
{
	//TODO: 수정
	if (m_pPlayerCurPokemon->GetCurState() == PokemonState::Faint)
		m_curBattleSituation = BattleSituation::Player_CanNot_Battle;
	else if (m_pOppoentCurPokemon->GetCurState() == PokemonState::Faint)
		m_curBattleSituation = BattleSituation::Opponet_CanNot_Battle;
	else
		m_curBattleSituation = BattleSituation::BothSide_Can_Battle;
}
