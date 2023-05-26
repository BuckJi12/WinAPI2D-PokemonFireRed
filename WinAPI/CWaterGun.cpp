#include "framework.h"
#include "CWaterGun.h"

CWaterGun::CWaterGun()
{
	// 기술 정보
	m_moveStat.name			= L"물대포";
	m_moveStat.description	= L"";
	m_moveStat.moveType		= L"물";
	m_moveStat.maxPP		= 25;
	m_moveStat.curPP		= 25;
	m_moveStat.moveDamage	= 40;

	// 기술 타입
	m_moveType				= PokemonType::Water;

	// 기술 종류
	m_moveKind				= MoveKind::Special;
}

CWaterGun::~CWaterGun()
{
}

void CWaterGun::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
