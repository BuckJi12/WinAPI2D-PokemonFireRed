#include "framework.h"
#include "CEmber.h"

CEmber::CEmber()
{
	// ��� ����
	m_moveStat.name			= L"�Ҳɼ���";
	m_moveStat.description	= L"";
	m_moveStat.moveType		= L"�Ҳ�";
	m_moveStat.maxPP		= 25;
	m_moveStat.curPP		= 25;
	m_moveStat.moveDamage	= 40;

	// ��� Ÿ��
	m_moveType				= PokemonType::Fire;

	// ��� ����
	m_moveKind				= MoveKind::Special;
}

CEmber::~CEmber()
{
}

void CEmber::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
