#include "framework.h"
#include "CMasterBall.h"

CMasterBall::CMasterBall()
{
	m_itemData.name			= L"�����ͺ�";
	m_itemData.description	= L"�߻� ���ϸ��� �ݵ�� ���� �� �ִ� �ְ� ������ ��";
	m_itemData.count		= 1;
	m_itemData.cost			= 100000;
	m_itemData.rate			= 255.0f;
}

CMasterBall::~CMasterBall()
{
}
