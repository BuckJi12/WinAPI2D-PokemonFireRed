#include "framework.h"
#include "CWaterPulse.h"

CWaterPulse::CWaterPulse()
{
	// ��� ����
	m_moveStat.name = L"�����ĵ�";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"��";
	m_moveStat.maxPP = 20;
	m_moveStat.curPP = 20;
	m_moveStat.moveDamage = 60;

	// ��� Ÿ��
	m_moveType = PokemonType::Water;

	// ��� ����
	m_moveKind = MoveKind::Special;
}

CWaterPulse::~CWaterPulse()
{
}

void CWaterPulse::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
