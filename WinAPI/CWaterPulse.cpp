#include "framework.h"
#include "CWaterPulse.h"

CWaterPulse::CWaterPulse()
{
	// 기술 정보
	m_moveStat.name = L"물의파동";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"물";
	m_moveStat.maxPP = 20;
	m_moveStat.curPP = 20;
	m_moveStat.moveDamage = 60;

	// 기술 타입
	m_moveType = PokemonType::Water;

	// 기술 종류
	m_moveKind = MoveKind::Special;
}

CWaterPulse::~CWaterPulse()
{
}

void CWaterPulse::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
