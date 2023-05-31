#include "framework.h"
#include "CHydroPump.h"

CHydroPump::CHydroPump()
{
	// ��� ����
	m_moveStat.name = L"���̵������";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"��";
	m_moveStat.maxPP = 5;
	m_moveStat.curPP = 5;
	m_moveStat.moveDamage = 110;

	// ��� Ÿ��
	m_moveType = PokemonType::Water;

	// ��� ����
	m_moveKind = MoveKind::Special;
}

CHydroPump::~CHydroPump()
{
}

void CHydroPump::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
