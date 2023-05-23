#include "framework.h"
#include "CTurnBag.h"

#include "CBagWindow.h"

CTurnBag::CTurnBag(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pImageBagWindow	= nullptr;
	m_curCount			= 0;
}

CTurnBag::~CTurnBag()
{
}

void CTurnBag::CurSorControl()
{
	if (BUTTONDOWN(VK_DOWN))
		m_curCount += 1;
	else if (BUTTONDOWN(VK_UP))
		m_curCount -= 1;

	if (m_curCount >= PLAYER->GetPlayerItemList().size())
		m_curCount = 0;
	
	if (m_curCount < 0)
		m_curCount = PLAYER->GetPlayerItemList().size() - 1;

	switch (m_curCount)
	{
	case 0:
		m_battleScene->GetCursor()->SetPos(273, 24);
		break;
	case 1:
		m_battleScene->GetCursor()->SetPos(273, 84);
		break;
	}

	if (BUTTONDOWN(VK_SPACE))
	{
		if (PLAYER->GetPlayerItemList()[m_curCount]->GetItemData().count > 1)
		{
			PLAYER->GetPlayerItemList()[m_curCount]->UseItem();
			if (PLAYER->GetPlayerItemList()[m_curCount]->GetItemData().count == 0)
			{
				//TODO: 인벤토리에서 제거
			}
			//TODO: 아이템 사용으로 이동
		}
	}
}

void CTurnBag::Init()
{
	m_pImageBagWindow = new CBagWindow;
	m_pImageBagWindow->Init();
	m_pImageBagWindow->SetPos(1000, 1000);
	m_battleScene->AddObjectThisScene(m_pImageBagWindow);
}

void CTurnBag::Enter()
{
	m_curCount = 0;
	m_pImageBagWindow->SetPos(0, 0);
}

void CTurnBag::Update()
{
	CurSorControl();

	if (BUTTONDOWN(VK_ESCAPE))
	{
		m_battleScene->ChangeTurn(PlayerAction::ChooseAction);
	}
}

void CTurnBag::Exit()
{
	m_pImageBagWindow->SetPos(1000, 1000);
	m_battleScene->GetCursor()->SetPos(1000, 1000);
}

void CTurnBag::Release()
{
	DELETEOBJECT(m_pImageBagWindow);
}
