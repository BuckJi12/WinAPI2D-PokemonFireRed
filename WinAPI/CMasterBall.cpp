#include "framework.h"
#include "CMasterBall.h"

CMasterBall::CMasterBall()
{
	m_itemData.name			= L"마스터볼";
	m_itemData.description	= L"야생 포켓몬을 반드시 잡을 수 있는 최고 성능의 볼";
	m_itemData.count		= 1;
	m_itemData.cost			= 100000;
	m_itemData.rate			= 255.0f;
	m_itemData.type			= ItemType::Ball;
}

CMasterBall::~CMasterBall()
{
}

void CMasterBall::Init()
{
	m_pImage = RESOURCE->LoadImg(L"MasterBall", L"Image\\Item\\MasterBall.png");
}
