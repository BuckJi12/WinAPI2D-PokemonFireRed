#include "framework.h"
#include "CMonsterBall.h"

CMonsterBall::CMonsterBall()
{
	m_itemData.name			= L"몬스터볼";
	m_itemData.description	= L"야생 포켓몬에게 던져서 잡기 위한 볼, 캡슐식으로 되어 있다.";
	m_itemData.count		= 1;
	m_itemData.cost			= 1000;
	m_itemData.rate			= 1.0f;
}

CMonsterBall::~CMonsterBall()
{
}

void CMonsterBall::Init()
{
	m_pImage = RESOURCE->LoadImg(L"MonsterBall", L"Image\\Item\\MonsterBall.png");
}