#include "framework.h"
#include "CMove.h"

CMove::CMove()
{
	// 기술 정보
	m_moveStat.name			= L"";
	m_moveStat.description	= L"";
	m_moveStat.moveType		= L"";
	m_moveStat.maxPP		= 35;
	m_moveStat.curPP		= 35;
	m_moveStat.moveDamage	= 1;

	// 기술 타입
	m_moveType				= PokemonType::Normal;

	// 기술 종류
	m_moveKind				= MoveKind::Physics;
	m_isLearned				= false;
}

CMove::~CMove()
{
}

CMove::CMove(const CMove& move)
{
	m_moveStat	= move.m_moveStat;
	m_moveType	= move.m_moveType;
	m_moveKind	= move.m_moveKind;
	m_isLearned = move.m_isLearned;
}

MoveStats CMove::GetMoveStat()
{
	return m_moveStat;
}

PokemonType CMove::GetType()
{
	return m_moveType;
}

MoveKind CMove::GetKind()
{
	return m_moveKind;
}

bool CMove::GetIsLearned()
{
	return m_isLearned;
}

void CMove::SetLearned(bool isLearned)
{
	m_isLearned = isLearned;
}

void CMove::UseMove(CPokemon* pokemon)
{
	m_moveStat.curPP -= 1;
}

void CMove::RecoverPP()
{
	m_moveStat.curPP = m_moveStat.curPP;
}
