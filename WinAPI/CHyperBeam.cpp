#include "framework.h"
#include "CHyperBeam.h"

CHyperBeam::CHyperBeam()
{
	// 기술 정보
	m_moveStat.name = L"파괴광선";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"노말";
	m_moveStat.maxPP = 5;
	m_moveStat.curPP = 5;
	m_moveStat.moveDamage = 120;

	// 기술 타입
	m_moveType = PokemonType::Normal;

	// 기술 종류
	m_moveKind = MoveKind::Physics;
}

CHyperBeam::~CHyperBeam()
{
}

void CHyperBeam::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
