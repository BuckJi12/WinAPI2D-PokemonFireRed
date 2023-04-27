#include "framework.h"
#include "COpponentFloor.h"

COpponentFloor::COpponentFloor()
{
	m_pImage = nullptr;
	m_point = Vector(425, 125);
}

COpponentFloor::~COpponentFloor()
{
}

void COpponentFloor::Init()
{
	m_pImage = RESOURCE->LoadImg(L"OppFloor", L"Image\\Battle\\OppFloor.png");
}

void COpponentFloor::Update()
{
	if (m_vecPos.x < m_point.x)
	{
		m_vecPos.x += 1000 * DT;
	}
}

void COpponentFloor::Render()
{
	CImageObject::Render();
}

void COpponentFloor::Release()
{
}
