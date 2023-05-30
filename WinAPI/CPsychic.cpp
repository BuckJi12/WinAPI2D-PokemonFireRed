#include "framework.h"
#include "CPsychic.h"

CPsychic::CPsychic()
{
	// ��� ����
	m_moveStat.name			= L"������Ű�׽ý�";
	m_moveStat.description	= L"";
	m_moveStat.moveType		= L"������";
	m_moveStat.maxPP		= 10;
	m_moveStat.curPP		= 10;
	m_moveStat.moveDamage	= 90;

	// ��� Ÿ��
	m_moveType = PokemonType::Psychic;

	// ��� ����
	m_moveKind = MoveKind::Special;
}

CPsychic::~CPsychic()
{
}

void CPsychic::UseMove(CPokemon* pokemon)
{
	CMove::UseMove(pokemon);
}
