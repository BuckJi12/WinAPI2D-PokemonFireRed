#include "framework.h"
#include "CThunderBolt.h"

CThunderBolt::CThunderBolt()
{
	// 기술 정보
	m_moveStat.name			= L"10만볼트";
	m_moveStat.description	= L"";
	m_moveStat.moveType		= L"전기";
	m_moveStat.maxPP		= 10;
	m_moveStat.curPP		= 10;
	m_moveStat.moveDamage	= 90;

	// 기술 타입
	m_moveType = PokemonType::Electric;

	// 기술 종류
	m_moveKind = MoveKind::Special;
}

CThunderBolt::~CThunderBolt()
{
}

void CThunderBolt::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
