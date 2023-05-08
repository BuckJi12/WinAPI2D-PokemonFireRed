#include "framework.h"
#include "CTurnChooseAction.h"

#include "CChooseWindow.h"

CTurnChooseAction::CTurnChooseAction(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pChooseWindow = nullptr;
	m_cursorState = CursorState::Fight;
	m_curCount = 0;
}

CTurnChooseAction::~CTurnChooseAction()
{
}

void CTurnChooseAction::CursorControl()
{
	/*if (BUTTONDOWN(VK_RIGHT))
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

	m_cursorState = (CursorState)m_cursorState;

	switch (m_curCount)
	{
	case 0:
		m_pCursor->SetPos(410, 435);
		break;
	case 1:
		m_pCursor->SetPos(590, 435);
		break;
	case 2:
		m_pCursor->SetPos(410, 490);
		break;
	case 3:
		m_pCursor->SetPos(590, 490);
		break;
	}*/
}

void CTurnChooseAction::Init()
{
	m_pChooseWindow = new CChooseWindow;
	m_pChooseWindow->Init();
	m_pChooseWindow->SetPos(1000, 1000);
	m_battleScene->AddObjectThisScene(m_pChooseWindow);

	//m_pCursor = new CImageObject;
	//m_pCursor->SetImage(RESOURCE->LoadImg(L"Cursor",L"Image\\Battle\\Cursor.png"));
	//m_pCursor->SetLayer(Layer::Environment3);
	//m_battleScene->AddObjectThisScene(m_pCursor);
}

void CTurnChooseAction::Enter()
{
	m_pChooseWindow->SetPos(400, 400);
	m_cursorState = CursorState::Fight;
	m_curCount = 0;
}

void CTurnChooseAction::Update()
{
	CursorControl();
}

void CTurnChooseAction::Exit()
{
	m_pChooseWindow->SetPos(1000, 1000);
}

void CTurnChooseAction::Release()
{
}