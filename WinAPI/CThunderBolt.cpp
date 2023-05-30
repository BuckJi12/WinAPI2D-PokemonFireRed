#include "framework.h"
#include "CThunderBolt.h"

CThunderBolt::CThunderBolt()
{
	// ��� ����
	m_moveStat.name			= L"10����Ʈ";
	m_moveStat.description	= L"";
	m_moveStat.moveType		= L"����";
	m_moveStat.maxPP		= 10;
	m_moveStat.curPP		= 10;
	m_moveStat.moveDamage	= 90;

	// ��� Ÿ��
	m_moveType = PokemonType::Electric;

	// ��� ����
	m_moveKind = MoveKind::Special;
}

CThunderBolt::~CThunderBolt()
{
}

void CThunderBolt::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
