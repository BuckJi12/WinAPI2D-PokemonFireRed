#include "framework.h"
#include "CTurnEnter.h"

#include "CImageObject.h"
#include "CPlayerFloor.h"
#include "COpponentFloor.h"
#include "CPlayerThrowBall.h"

CTurnEnter::CTurnEnter(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pImagePlayerFloor		= nullptr;
	m_pImageNoramUI			= nullptr;
	m_pImageOpponentFloor	= nullptr;
	m_pImagePlayerThrow     = nullptr;
}

CTurnEnter::~CTurnEnter()
{
}

void CTurnEnter::Init()
{
	// 환경
	m_pImagePlayerFloor = new CPlayerFloor;
	m_pImageOpponentFloor = new COpponentFloor;

	// 플레이어
	m_pImagePlayerThrow = new CPlayerThrowBall;

	//TODO: 별도 텍스트 박스로 만들기
	m_pImageNoramUI = new CImageObject;
	m_pImageNoramUI->SetPos(0, 400);
	m_pImageNoramUI->SetImage(RESOURCE->LoadImg(L"TextBox", L"Image\\Battle\\TextBox.png"));
}

void CTurnEnter::Enter()
{
	m_pImagePlayerFloor->SetPos(1600, 335);

	m_pImagePlayerThrow->Setting(Vector(1802, 272));

	m_pImageOpponentFloor->SetPos(-1025, 125);
	BATTLE->GetOpponentCurPokemon()->SetAnimation();
	m_pImageOpponentFloor->SetChild(BATTLE->GetOpponentCurPokemon());

	m_battleScene->AddObjectThisScene(m_pImagePlayerFloor);
	m_battleScene->AddObjectThisScene(m_pImageOpponentFloor);
	m_battleScene->AddObjectThisScene(m_pImagePlayerThrow);
	m_battleScene->AddObjectThisScene(BATTLE->GetOpponentCurPokemon());
	m_battleScene->AddObjectThisScene(m_pImageNoramUI);
}

void CTurnEnter::Update()
{
	if (BUTTONDOWN(VK_SPACE))
	{
		BATTLE->ChooseAction(PlayerAction::PlayerReady);
	}
}

void CTurnEnter::Exit()
{
}

void CTurnEnter::Release()
{
}
