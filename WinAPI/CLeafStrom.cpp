#include "framework.h"
#include "CLeafStrom.h"

CLeafStrom::CLeafStrom()
{
	// ��� ����
	m_moveStat.name = L"��������";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"Ǯ";
	m_moveStat.maxPP = 5;
	m_moveStat.curPP = 5;
	m_moveStat.moveDamage = 120;

	// ��� Ÿ��
	m_moveType = PokemonType::Grass;

	// ��� ����
	m_moveKind = MoveKind::Special;
}

CLeafStrom::~CLeafStrom()
{
}

void CLeafStrom::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
