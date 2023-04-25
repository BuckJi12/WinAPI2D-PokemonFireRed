#include "framework.h"
#include "CTackle.h"

CTackle::CTackle()
{
	// ��� ����
	m_moveStat.name = L"�����ġ��";
	m_moveStat.description = L"";
	m_moveStat.maxPP = 35;
	m_moveStat.curPP = 35;
	m_moveStat.moveDamage = 40;

	// ��� Ÿ��
	m_moveType = PokemonType::Normal;

	// ��� ����
	m_moveKind = MoveKind::Physics;
}

CTackle::~CTackle()
{
}

void CTackle::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
