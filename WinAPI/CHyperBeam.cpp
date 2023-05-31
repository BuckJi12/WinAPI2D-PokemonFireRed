#include "framework.h"
#include "CHyperBeam.h"

CHyperBeam::CHyperBeam()
{
	// ��� ����
	m_moveStat.name = L"�ı�����";
	m_moveStat.description = L"";
	m_moveStat.moveType = L"�븻";
	m_moveStat.maxPP = 5;
	m_moveStat.curPP = 5;
	m_moveStat.moveDamage = 120;

	// ��� Ÿ��
	m_moveType = PokemonType::Normal;

	// ��� ����
	m_moveKind = MoveKind::Physics;
}

CHyperBeam::~CHyperBeam()
{
}

void CHyperBeam::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
