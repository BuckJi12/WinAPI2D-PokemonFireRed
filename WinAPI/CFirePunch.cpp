#include "framework.h"
#include "CFirePunch.h"

CFirePunch::CFirePunch()
{
	// ��� ����
	m_moveStat.name = L"�Ҳ���ġ";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"�Ҳ�";
	m_moveStat.maxPP = 15;
	m_moveStat.curPP = 15;
	m_moveStat.moveDamage = 75;

	// ��� Ÿ��
	m_moveType = PokemonType::Fire;

	// ��� ����
	m_moveKind = MoveKind::Physics;
}

CFirePunch::~CFirePunch()
{
}

void CFirePunch::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
