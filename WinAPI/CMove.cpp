#include "framework.h"
#include "CMove.h"

CMove::CMove()
{
}

CMove::~CMove()
{
}

void CMove::RecoverPP(int value)
{
	m_moveStat.curPP = value;
}
