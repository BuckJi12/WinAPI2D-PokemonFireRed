#include "framework.h"
#include "CMonsterBall.h"

CMonsterBall::CMonsterBall()
{
	m_name			= L"���ͺ�";
	m_description	= L"�߻� ���ϸ󿡰� ������ ��� ���� ��, ĸ�������� �Ǿ� �ִ�.";

	m_count			= 1;
	m_cost			= 1000;
	m_rate			= 1.0f;
}

CMonsterBall::~CMonsterBall()
{
}

void CMonsterBall::Init()
{
	m_pImage = RESOURCE->LoadImg(L"MonsterBall", L"Image\\Item\\MonsterBall.png");
}

void CMonsterBall::Update()
{
}

void CMonsterBall::Render()
{
}

void CMonsterBall::Release()
{
}
