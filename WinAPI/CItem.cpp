#include "framework.h"
#include "CItem.h"

CItem::CItem()
{
	m_name			= L"";
	m_description	= L"";

	m_count			= 0;
	m_cost			= 0;
	m_rate			= 0;
}

CItem::~CItem()
{
}

void CItem::Init()
{
}

void CItem::Update()
{
}

void CItem::Render()
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

void CItem::Release()
{
}
