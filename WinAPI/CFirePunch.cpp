#include "framework.h"
#include "CFirePunch.h"

CFirePunch::CFirePunch()
{
	// 기술 정보
	m_moveStat.name = L"불꽃펀치";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"불꽃";
	m_moveStat.maxPP = 15;
	m_moveStat.curPP = 15;
	m_moveStat.moveDamage = 75;

	// 기술 타입
	m_moveType = PokemonType::Fire;

	// 기술 종류
	m_moveKind = MoveKind::Physics;
}

CFirePunch::~CFirePunch()
{
}

void CFirePunch::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
