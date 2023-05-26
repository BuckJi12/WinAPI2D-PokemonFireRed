#include "framework.h"
#include "CVineWhip.h"

CVineWhip::CVineWhip()
{
	// ��� ����
	m_moveStat.name			= L"����ä��";
	m_moveStat.description	= L"";
	m_moveStat.moveType		= L"Ǯ";
	m_moveStat.maxPP		= 25;
	m_moveStat.curPP		= 25;
	m_moveStat.moveDamage	= 45;

	// ��� Ÿ��
	m_moveType = PokemonType::Grass;

	// ��� ����
	m_moveKind = MoveKind::Physics;
}

CVineWhip::~CVineWhip()
{
}

void CVineWhip::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
