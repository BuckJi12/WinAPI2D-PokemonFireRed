#include "framework.h"
#include "CTurnChooseAction.h"

#include "CChooseWindow.h"

CTurnChooseAction::CTurnChooseAction(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pChooseWindow = nullptr;
	m_curCount = 0;
}

CTurnChooseAction::~CTurnChooseAction()
{
}

void CTurnChooseAction::CursorControl()
{
	if (BUTTONDOWN(VK_RIGHT))
		m_curCount += 1;
	else if (BUTTONDOWN(VK_DOWN))
		m_curCount += 2;
	else if (BUTTONDOWN(VK_LEFT))
		m_curCount -= 1;
	else if (BUTTONDOWN(VK_UP))
		m_curCount -= 2;

	if (m_curCount > 3)
	{
		if (m_curCount == 4)
			m_curCount = 0;
		else
			m_curCount = 1;
	}
	else if (m_curCount < 0)
	{
		if (m_curCount == -1)
			m_curCount = 3;
		else
			m_curCount = 2;
	}

	switch (m_curCount)
	{
	case 0:
		m_battleScene->GetCursor()->SetPos(410, 435);
		break;
	case 1:
		m_battleScene->GetCursor()->SetPos(590, 435);
		break;
	case 2:
		m_battleScene->GetCursor()->SetPos(410, 490);
		break;
	case 3:
		m_battleScene->GetCursor()->SetPos(590, 490);
		break;
	}

	if (BUTTONDOWN(VK_SPACE))
	{
		switch (m_curCount)
		{
		case 0:
			m_battleScene->ChangeTurn(PlayerAction::ChooseMove);
			break;
		case 1:
			m_battleScene->ChangeTurn(PlayerAction::Bag);
			break;
		case 2:
			m_battleScene->ChangeTurn(PlayerAction::Change);
			break;
		case 3:
			Exit();
			SCENE->ChangePrevScene();
			GAME->SetRandomValue();
			break;
		}
	}
}

void CTurnChooseAction::Init()
{
	m_pChooseWindow = new CChooseWindow;
	m_pChooseWindow->Init();
	m_pChooseWindow->SetPos(1000, 1000);
	m_battleScene->AddObjectThisScene(m_pChooseWindow);
}

void CTurnChooseAction::Enter()
{
	m_pChooseWindow->SetPos(400, 400);
	m_curCount = 0;
}

void CTurnChooseAction::Update()
{
	CursorControl();
}

void CTurnChooseAction::Exit()
{
	m_pChooseWindow->SetPos(1000, 1000);
	m_battleScene->GetCursor()->SetPos(1000, 1000);
}

void CTurnChooseAction::Release()
{
	DELETEOBJECT(m_pChooseWindow);
}
