#include "framework.h"
#include "CTurnBag.h"

#include "CBagWindow.h"

CTurnBag::CTurnBag(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pImageBagWindow = nullptr;
}

CTurnBag::~CTurnBag()
{
}

void CTurnBag::Init()
{
	m_pImageBagWindow = new CBagWindow;
	m_pImageBagWindow->SetPos(1000, 1000);
	m_battleScene->AddObjectThisScene(m_pImageBagWindow);
}

void CTurnBag::Enter()
{
	m_pImageBagWindow->SetPos(0, 0);
}

void CTurnBag::Update()
{
	if (BUTTONDOWN(VK_ESCAPE))
	{
		m_battleScene->ChangeTurn(PlayerAction::ChooseAction);
	}
}

void CTurnBag::Exit()
{
	m_pImageBagWindow->SetPos(1000, 1000);
}

void CTurnBag::Release()
{
	DELETEOBJECT(m_pImageBagWindow);
}
