#include "framework.h"
#include "CThunderPunch.h"

CThunderPunch::CThunderPunch()
{
	// 기술 정보
	m_moveStat.name = L"번개펀치";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"전기";
	m_moveStat.maxPP = 15;
	m_moveStat.curPP = 15;
	m_moveStat.moveDamage = 75;

	// 기술 타입
	m_moveType = PokemonType::Electric;

	// 기술 종류
	m_moveKind = MoveKind::Physics;
}

CThunderPunch::~CThunderPunch()
{
}

void CThunderPunch::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
