#include "framework.h"
#include "CBattleManager.h"

#include "CItem.h"

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
	m_pOpponentCurMove		= nullptr;
	m_curAction				= PlayerAction::Enter;
	m_curFirstAttack		= FirstAttack::Player;
	m_playerCurInex			= 0;
	m_curBattleSituation	= BattleSituation::BothSide_Can_Battle;
	m_battleResult			= BattleResult::Win;
	m_curMoveResult			= MoveResult::Normal;

	m_catchRate				= 1;
	m_isCatching			= false;
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

BattleResult CBattleManager::GetBattleResult()
{
	return m_battleResult;
}

MoveResult CBattleManager::GetMoveResult()
{
	return m_curMoveResult;
}

CMove* CBattleManager::GetCurMove()
{
	return m_pPlayerCurPokemon->GetPokemonMoveList()[m_playerCurInex];
}

CMove* CBattleManager::GetCurOpponentMove()
{
	return m_pOpponentCurMove;
}

void CBattleManager::OpponentSelectMove()
{
	int random;
	while (true)
	{
		random = rand() % m_pOppoentCurPokemon->GetPokemonMoveList().size();
		if (m_pOppoentCurPokemon->GetPokemonMoveList()[random]->GetMoveStat().curPP > 0)
			break;
	}

	m_pOpponentCurMove = m_pOppoentCurPokemon->GetPokemonMoveList()[random];
}

void CBattleManager::SetBattleResult(BattleResult result)
{
	m_battleResult = result;
}

void CBattleManager::SetFirstAttack(FirstAttack attack)
{
	m_curFirstAttack = attack;
}

void CBattleManager::SetBattleSituation(BattleSituation situation)
{
	m_curBattleSituation = situation;
}

void CBattleManager::BattleInit()
{
	m_pPlayerCurPokemon = PLAYER->GetPlayerFirstPokemon();
	m_pOppoentCurPokemon = new CPokemon();
	m_pOppoentCurPokemon = POKEMON->FindPokemon(7);
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
	m_pPlayerCurPokemon->GetPokemonMoveList()[m_playerCurInex]->UseMove(m_pOppoentCurPokemon);
	m_pOppoentCurPokemon->TakeDamage(CalculateDamage(m_pPlayerCurPokemon, m_pOppoentCurPokemon,
		m_pPlayerCurPokemon->GetPokemonMoveList()[m_playerCurInex]));
	IsGoodEffect(m_pPlayerCurPokemon, m_pOppoentCurPokemon, 
		m_pPlayerCurPokemon->GetPokemonMoveList()[m_playerCurInex]);
	CheckBattleAble();
}

void CBattleManager::OppoentUseMove()
{
	m_pOpponentCurMove->UseMove(m_pPlayerCurPokemon);
	m_pPlayerCurPokemon->TakeDamage(CalculateDamage(m_pOppoentCurPokemon, m_pPlayerCurPokemon,
		m_pOpponentCurMove));
	IsGoodEffect(m_pOppoentCurPokemon, m_pPlayerCurPokemon,
		m_pOpponentCurMove);
	CheckBattleAble();
}

void CBattleManager::SelectMove(int index)
{
	m_playerCurInex = index;
}

int CBattleManager::CalculateDamage(CPokemon* attacker, CPokemon* victim, CMove* move)
{
	int damage;
	if (move->GetKind() == MoveKind::Physics)
	{
		damage = ((((((attacker->GetPokemonStat().level * 2 / 5) + 2) * move->GetMoveStat().moveDamage *
			attacker->GetPokemonStat().attack / 50) / victim->GetPokemonStat().defence) * 1) + 2) *
			typeDamage[(int)move->GetType()][(int)victim->GetType(1)] * typeDamage[(int)move->GetType()][(int)victim->GetType(2)];
	}
	else
	{
		damage = ((((((attacker->GetPokemonStat().level * 2 / 5) + 2) * move->GetMoveStat().moveDamage *
			attacker->GetPokemonStat().specialAttack / 50) / victim->GetPokemonStat().specialDefence) * 1) + 2) *
			typeDamage[(int)move->GetType()][(int)victim->GetType(1)] * typeDamage[(int)move->GetType()][(int)victim->GetType(2)];
	}

	return damage;
}

int CBattleManager::CalculateCatchRate(CItem* item)
{
	float fNum;

	fNum = ((((3 * m_pOppoentCurPokemon->GetPokemonStat().maxHp) - (2 * m_pOppoentCurPokemon->GetPokemonStat().curHp))
		* m_pOppoentCurPokemon->GetPokemonInfo().rate * 1 * item->GetItemData().rate) / (3 * m_pOppoentCurPokemon->GetPokemonStat().maxHp));
	m_catchRate = 65535 * pow((fNum / 255), 1.0 / 4);

	return m_catchRate;
}

void CBattleManager::PokemonChanage(CPokemon* pokemon)
{
	// TODO: 수정
	m_pPlayerCurPokemon = pokemon;
}

bool CBattleManager::PlayerCheckBattleAble()
{
	for (int i = 0; i < PLAYER->GetPlayerPokemonList().size(); i++)
	{
		if (PLAYER->GetPlayerPokemonList()[i]->GetCurState() == PokemonState::Faint)
			continue;

		return true;
	}

	return false;
}

void CBattleManager::IsGoodEffect(CPokemon* attacker, CPokemon* victim, CMove* move)
{
	float result =typeDamage[(int)move->GetType()][(int)victim->GetType(1)] * 
		typeDamage[(int)move->GetType()][(int)victim->GetType(2)];

	if (result >= 2)
		m_curMoveResult = MoveResult::Good;
	else if (result < 1)
		m_curMoveResult = MoveResult::Bad;
	else if (result == 0)
		m_curMoveResult = MoveResult::Nothing;
	else
		m_curMoveResult = MoveResult::Normal;
}

CatchResult CBattleManager::TryPokemonCatch()
{
	srand(time(NULL));
	int number1 = rand() % 65535 + 1;
	int number2 = rand() % 60535 + 5000;
	int number3 = rand() % 55535 + 10000;

	if (m_catchRate < number1)			// Number1 보다 작으면 Fail1
		return CatchResult::Fail1;

	if (m_catchRate < number2)			// Number2 보다 작으면 Fail2
		return CatchResult::Fail2;

	if (m_catchRate < number3)			// Number3 보다 작으면 Fail3
		return CatchResult::Fail3;
	else								// Number3 보다 크면 Success			
		return CatchResult::Success;
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
