#include "framework.h"
#include "CPsychic.h"

CPsychic::CPsychic()
{
	// 기술 정보
	m_moveStat.name			= L"사이코키네시스";
	m_moveStat.description	= L"";
	m_moveStat.moveType		= L"에스퍼";
	m_moveStat.maxPP		= 10;
	m_moveStat.curPP		= 10;
	m_moveStat.moveDamage	= 90;

	// 기술 타입
	m_moveType = PokemonType::Psychic;

	// 기술 종류
	m_moveKind = MoveKind::Special;
}

CPsychic::~CPsychic()
{
}

void CPsychic::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
