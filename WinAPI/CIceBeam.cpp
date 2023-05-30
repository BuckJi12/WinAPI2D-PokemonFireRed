#include "framework.h"
#include "CIceBeam.h"

CIceBeam::CIceBeam()
{
	// ��� ����
	m_moveStat.name			= L"�õ���";
	m_moveStat.description	= L"";
	m_moveStat.moveType		= L"����";
	m_moveStat.maxPP		= 10;
	m_moveStat.curPP		= 10;
	m_moveStat.moveDamage	= 90;

	// ��� Ÿ��
	m_moveType = PokemonType::Ice;

	// ��� ����
	m_moveKind = MoveKind::Special;
}

CIceBeam::~CIceBeam()
{
}

void CIceBeam::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
