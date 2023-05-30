#include "framework.h"
#include "CIceBeam.h"

CIceBeam::CIceBeam()
{
	// 기술 정보
	m_moveStat.name			= L"냉동빔";
	m_moveStat.description	= L"";
	m_moveStat.moveType		= L"얼음";
	m_moveStat.maxPP		= 10;
	m_moveStat.curPP		= 10;
	m_moveStat.moveDamage	= 90;

	// 기술 타입
	m_moveType = PokemonType::Ice;

	// 기술 종류
	m_moveKind = MoveKind::Special;
}

CIceBeam::~CIceBeam()
{
}

void CIceBeam::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
