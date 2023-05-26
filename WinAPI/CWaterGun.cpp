#include "framework.h"
#include "CWaterGun.h"

CWaterGun::CWaterGun()
{
	// ��� ����
	m_moveStat.name			= L"������";
	m_moveStat.description	= L"";
	m_moveStat.moveType		= L"��";
	m_moveStat.maxPP		= 25;
	m_moveStat.curPP		= 25;
	m_moveStat.moveDamage	= 40;

	// ��� Ÿ��
	m_moveType				= PokemonType::Water;

	// ��� ����
	m_moveKind				= MoveKind::Special;
}

CWaterGun::~CWaterGun()
{
}

void CWaterGun::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
