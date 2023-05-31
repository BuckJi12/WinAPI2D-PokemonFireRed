#include "framework.h"
#include "CFireBlast.h"

CFireBlast::CFireBlast()
{
	// ��� ����
	m_moveStat.name = L"�Ҵ빮��";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"�Ҳ�";
	m_moveStat.maxPP = 5;
	m_moveStat.curPP = 5;
	m_moveStat.moveDamage = 110;

	// ��� Ÿ��
	m_moveType = PokemonType::Fire;

	// ��� ����
	m_moveKind = MoveKind::Special;
}

CFireBlast::~CFireBlast()
{
}

void CFireBlast::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
