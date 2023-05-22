#include "framework.h"
#include "CItem.h"

CItem::CItem()
{
	m_itemData.name			= L"";
	m_itemData.description	= L"";
	m_itemData.count		= 0;
	m_itemData.cost			= 0;
	m_itemData.rate			= 0;
}

CItem::~CItem()
{
}

void CItem::Init()
{
}

CImage* CItem::GetImage()
{
	return m_pImage;
}

ItemData CItem::GetItemData()
{
	return m_itemData;
}
