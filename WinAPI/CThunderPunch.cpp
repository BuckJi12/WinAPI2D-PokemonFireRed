#include "framework.h"
#include "CThunderPunch.h"

CThunderPunch::CThunderPunch()
{
	// ��� ����
	m_moveStat.name = L"������ġ";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"����";
	m_moveStat.maxPP = 15;
	m_moveStat.curPP = 15;
	m_moveStat.moveDamage = 75;

	// ��� Ÿ��
	m_moveType = PokemonType::Electric;

	// ��� ����
	m_moveKind = MoveKind::Physics;
}

CThunderPunch::~CThunderPunch()
{
}

void CThunderPunch::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
