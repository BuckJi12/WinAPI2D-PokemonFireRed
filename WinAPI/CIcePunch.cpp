#include "framework.h"
#include "CIcePunch.h"

CIcePunch::CIcePunch()
{
	// 기술 정보
	m_moveStat.name = L"냉동펀치";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"얼음";
	m_moveStat.maxPP = 15;
	m_moveStat.curPP = 15;
	m_moveStat.moveDamage = 75;

	// 기술 타입
	m_moveType = PokemonType::Ice;

	// 기술 종류
	m_moveKind = MoveKind::Physics;
}

CIcePunch::~CIcePunch()
{
}

void CIcePunch::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
