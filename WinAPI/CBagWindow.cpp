#include "framework.h"
#include "CBagWindow.h"

CBagWindow::CBagWindow()
{
	m_layer				= Layer::Environment2;
	m_pItemIcon			= nullptr;
	m_itemDescription	= L"";
}

CBagWindow::~CBagWindow()
{
}

CImage* CBagWindow::GetItemIcon()
{
	return m_pItemIcon;
}

void CBagWindow::SetItem(CItem item)
{
	m_pItemIcon			= item.GetImage();
	m_itemDescription	= item.GetItemData().description;
}

void CBagWindow::Init()
{
	m_pImage = RESOURCE->LoadImg(L"BagWindow", L"Image\\Battle\\Bag_In_Battle.png");
}

void CBagWindow::Update()
{
}

void CBagWindow::Render()
{
	CImageObject::Render();

	if (m_pItemIcon != nullptr)
	{
		RENDER->Image(
			m_pItemIcon,
			23,
			461,
			109,
			559
		);
	}

	RENDER->Text(
		m_itemDescription,
		173,
		461,
		739,
		558,
		Color(0, 0, 0, 1),
		25
	);

	RENDER->Text(
		L"º¼",
		m_vecPos.x + 132,
		m_vecPos.y + 25,
		m_vecPos.x + 180,
		m_vecPos.y + 60,
		Color(0, 0, 0, 1),
		25
	);

	if (PLAYER->GetPlayerItemList().size() > 0)
	{
		RENDER->Text(
			PLAYER->GetPlayerItemList()[0]->GetItemData().name + L" X " +
			to_wstring(PLAYER->GetPlayerItemList()[0]->GetItemData().count),
			m_vecPos.x + 323,
			m_vecPos.y + 31,
			m_vecPos.x + 743,
			m_vecPos.y + 87,
			Color(0, 0, 0, 1),
			25
		);
	}

	if (PLAYER->GetPlayerItemList().size() > 1)
	{
		RENDER->Text(
			PLAYER->GetPlayerItemList()[1]->GetItemData().name + L" X " +
			to_wstring(PLAYER->GetPlayerItemList()[1]->GetItemData().count),
			m_vecPos.x + 323,
			m_vecPos.y + 94,
			m_vecPos.x + 743,
			m_vecPos.y + 150,
			Color(0, 0, 0, 1),
			25
		);
	}
}

void CBagWindow::Release()
{
}
