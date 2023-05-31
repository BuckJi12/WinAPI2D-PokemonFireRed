#include "framework.h"
#include "CFireBlast.h"

CFireBlast::CFireBlast()
{
	// 기술 정보
	m_moveStat.name = L"불대문자";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"불꽃";
	m_moveStat.maxPP = 5;
	m_moveStat.curPP = 5;
	m_moveStat.moveDamage = 110;

	// 기술 타입
	m_moveType = PokemonType::Fire;

	// 기술 종류
	m_moveKind = MoveKind::Special;
}

CFireBlast::~CFireBlast()
{
}

void CFireBlast::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
