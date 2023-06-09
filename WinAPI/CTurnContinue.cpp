#include "framework.h"
#include "CTurnContinue.h"

#include "CImageObject.h"

CTurnContinue::CTurnContinue(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pImageContinue	= nullptr;
	m_curCount			= 0;
}

CTurnContinue::~CTurnContinue()
{
}

void CTurnContinue::CurSorControl()
{
	if (BUTTONDOWN(VK_DOWN))
		m_curCount += 1;
	else if (BUTTONDOWN(VK_UP))
		m_curCount -= 1;

	if (m_curCount > 1)
		m_curCount = 0;
	if (m_curCount < 0)
		m_curCount = 1;

	switch (m_curCount)
	{
	case 0:
		m_battleScene->GetCursor()->SetPos(410, 435);
		break;
	case 1:
		m_battleScene->GetCursor()->SetPos(410, 490);
		break;
	}

	if (BUTTONDOWN(VK_SPACE))
	{
		switch (m_curCount)
		{
		case 0:
			//TODO: 포켓몬 필수 교체
			m_battleScene->SetTurnSituation(TurnSituation::MustChange);
			m_battleScene->ChangeTurn(PlayerAction::Change);
			break;
		case 1:
			Exit();
			SCENE->ChangePrevScene();
			GAME->SetRandomValue();
			break;
		}
	}
}

void CTurnContinue::Init()
{
	m_pImageContinue = new CImageObject;
	m_pImageContinue->SetImage(RESOURCE->LoadImg(L"ToBeContinue", L"Image\\Battle\\ToBeContinue.png"));
	m_pImageContinue->SetLayer(Layer::Environment2);
	m_pImageContinue->SetPos(1000, 1000);
	m_battleScene->AddObjectThisScene(m_pImageContinue);
}

void CTurnContinue::Enter()
{
	m_pImageContinue->SetPos(400, 400);
	m_battleScene->GetTextBox()->SetText(L"포켓몬을 \n교체하시겠습니까?");
}

void CTurnContinue::Update()
{
	CurSorControl();
}

void CTurnContinue::Exit()
{
	m_pImageContinue->SetPos(1000, 1000);
	m_battleScene->GetCursor()->SetPos(1000, 1000);
	m_battleScene->GetTextBox()->SetText(L"");
}

void CTurnContinue::Release()
{
	DELETEOBJECT(m_pImageContinue);
}
