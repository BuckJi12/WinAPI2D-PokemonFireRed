#include "framework.h"
#include "CTackle.h"

CTackle::CTackle()
{
	// 기술 정보
	m_moveStat.name = L"몸통박치기";
	m_moveStat.description = L"";
	m_moveStat.maxPP = 35;
	m_moveStat.curPP = 35;
	m_moveStat.moveDamage = 40;

	// 기술 타입
	m_moveType = PokemonType::Normal;

	// 기술 종류
	m_moveKind = MoveKind::Physics;
}

CTackle::~CTackle()
{
}

void CTackle::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
