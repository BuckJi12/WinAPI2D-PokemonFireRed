#include "framework.h"
#include "CVineWhip.h"

CVineWhip::CVineWhip()
{
	// 기술 정보
	m_moveStat.name			= L"덩굴채찍";
	m_moveStat.description	= L"";
	m_moveStat.moveType		= L"풀";
	m_moveStat.maxPP		= 25;
	m_moveStat.curPP		= 25;
	m_moveStat.moveDamage	= 45;

	// 기술 타입
	m_moveType = PokemonType::Grass;

	// 기술 종류
	m_moveKind = MoveKind::Physics;
}

CVineWhip::~CVineWhip()
{
}

void CVineWhip::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
