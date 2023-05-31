#include "framework.h"
#include "CLeafStrom.h"

CLeafStrom::CLeafStrom()
{
	// 기술 정보
	m_moveStat.name = L"리프스톰";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"풀";
	m_moveStat.maxPP = 5;
	m_moveStat.curPP = 5;
	m_moveStat.moveDamage = 120;

	// 기술 타입
	m_moveType = PokemonType::Grass;

	// 기술 종류
	m_moveKind = MoveKind::Special;
}

CLeafStrom::~CLeafStrom()
{
}

void CLeafStrom::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
