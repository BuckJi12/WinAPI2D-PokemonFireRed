#include "framework.h"
#include "CIcePunch.h"

CIcePunch::CIcePunch()
{
	// ��� ����
	m_moveStat.name = L"�õ���ġ";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"����";
	m_moveStat.maxPP = 15;
	m_moveStat.curPP = 15;
	m_moveStat.moveDamage = 75;

	// ��� Ÿ��
	m_moveType = PokemonType::Ice;

	// ��� ����
	m_moveKind = MoveKind::Physics;
}

CIcePunch::~CIcePunch()
{
}

void CIcePunch::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
