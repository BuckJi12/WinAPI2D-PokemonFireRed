#include "framework.h"
#include "CPlayerFloor.h"

CPlayerFloor::CPlayerFloor()
{
	m_pImage = nullptr;
	m_point = Vector(15, 335);
}

CPlayerFloor::~CPlayerFloor()
{
}

void CPlayerFloor::Init()
{
	m_pImage = RESOURCE->LoadImg(L"PlayerFloor", L"Image\\Battle\\PlayerFloor.png");
}

void CPlayerFloor::Update()
{
	if (m_vecPos.x > m_point.x)
	{
		m_vecPos.x -= 1000 * DT;
	}
}

void CPlayerFloor::Render()
{
	if (nullptr != m_pImage)
	{
		RENDER->Image(
			m_pImage,
			m_vecPos.x,
			m_vecPos.y,
			m_vecPos.x + (float)m_pImage->GetWidth(),
			m_vecPos.y + (float)m_pImage->GetHeight()
		);
	}
}

void CPlayerFloor::Release()
{
}
