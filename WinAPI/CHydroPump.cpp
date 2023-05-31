#include "framework.h"
#include "CHydroPump.h"

CHydroPump::CHydroPump()
{
	// 기술 정보
	m_moveStat.name = L"하이드로펌프";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"물";
	m_moveStat.maxPP = 5;
	m_moveStat.curPP = 5;
	m_moveStat.moveDamage = 110;

	// 기술 타입
	m_moveType = PokemonType::Water;

	// 기술 종류
	m_moveKind = MoveKind::Special;
}

CHydroPump::~CHydroPump()
{
}

void CHydroPump::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
