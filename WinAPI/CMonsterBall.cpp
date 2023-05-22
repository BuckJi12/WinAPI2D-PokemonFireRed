#include "framework.h"
#include "CMonsterBall.h"

CMonsterBall::CMonsterBall()
{
	m_itemData.name			= L"���ͺ�";
	m_itemData.description	= L"�߻� ���ϸ󿡰� ������ ��� ���� ��, ĸ�������� �Ǿ� �ִ�.";
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