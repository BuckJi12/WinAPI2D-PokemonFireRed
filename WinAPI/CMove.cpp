#include "framework.h"
#include "CMove.h"

CMove::CMove()
{
	// ��� ����
	m_moveStat.name = L"";
	m_moveStat.description = L"";
	m_moveStat.maxPP = 35;
	m_moveStat.curPP = 35;
	m_moveStat.moveDamage = 1;

	// ��� Ÿ��
	m_moveType = PokemonType::Normal;

	// ��� ����
	m_moveKind = MoveKind::Physics;
}

CMove::~CMove()
{
}

MoveStats CMove::GetMoveStat()
{
	return m_moveStat;
}

void CMove::UseMove()
{
	m_moveStat.curPP -= 1;
}

void CMove::RecoverPP(int value)
{
	m_moveStat.curPP = value;
}
