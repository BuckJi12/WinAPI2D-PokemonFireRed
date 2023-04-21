#include "framework.h"
#include "CMove.h"

CMove::CMove()
{
	// 기술 정보
	m_moveStat.name = L"";
	m_moveStat.description = L"";
	m_moveStat.maxPP = 35;
	m_moveStat.curPP = 35;
	m_moveStat.moveDamage = 1;

	// 기술 타입
	m_moveType = PokemonType::Normal;

	// 기술 종류
	m_moveKind = MoveKind::Physics;
}

CMove::~CMove()
{
}

void CMove::RecoverPP(int value)
{
	m_moveStat.curPP = value;
}
