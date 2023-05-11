#include "framework.h"
#include "CTurnEnter.h"

#include "CImageObject.h"
#include "CPlayerFloor.h"
#include "COpponentFloor.h"
#include "CPlayerThrowBall.h"
#include "COpponentStatUI.h"
#include "CPlayerStatUI.h"

CTurnEnter::CTurnEnter(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pImagePlayerFloor		= nullptr;
	m_pImageNoramUI			= nullptr;
	m_pImageOpponentFloor	= nullptr;
	m_pImagePlayerThrow     = nullptr;
	m_pImageOppStatUI		= nullptr;
}

CTurnEnter::~CTurnEnter()
{
}

void CTurnEnter::Init()
{
	// ȯ��
	m_pImagePlayerFloor = new CPlayerFloor;
	m_pImageOpponentFloor = new COpponentFloor;

	// �÷��̾�
	m_pImagePlayerThrow = new CPlayerThrowBall;

	// ��
	m_pImageOppStatUI = new COpponentStatUI;
	m_pImageOppStatUI->Init();

	//TODO: ���� �ؽ�Ʈ �ڽ��� �����
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
	BATTLE->GetOpponentCurPokemon()->AddObserver(m_pImageOppStatUI);

	m_pImageOppStatUI->SetPokemon(BATTLE->GetOpponentCurPokemon());
	m_pImageOppStatUI->SetPos(-1225, 50);

	// ������Ʈ �߰�
	m_battleScene->AddObjectThisScene(m_pImagePlayerFloor);
	m_battleScene->AddObjectThisScene(m_pImageOpponentFloor);
	m_battleScene->AddObjectThisScene(m_pImageOppStatUI);
	m_battleScene->AddObjectThisScene(m_pImagePlayerThrow);
	m_battleScene->AddObjectThisScene(BATTLE->GetOpponentCurPokemon());
	m_battleScene->AddObjectThisScene(m_pImageNoramUI);
} 

void CTurnEnter::Update()
{
	if (BUTTONDOWN(VK_SPACE))
	{
		m_battleScene->ChangeTurn(PlayerAction::PlayerReady);
	}
}

void CTurnEnter::Exit()
{
	m_pImagePlayerThrow->Play();
}

void CTurnEnter::Release()
{
	DELETEOBJECT(m_pImagePlayerFloor);
	DELETEOBJECT(m_pImageOpponentFloor);
	DELETEOBJECT(m_pImagePlayerThrow);
	DELETEOBJECT(m_pImageNoramUI);
	//DELETEOBJECT(BATTLE->GetOpponentCurPokemon());
	BATTLE->GetOpponentCurPokemon()->RemoveObserver(m_pImageOppStatUI);
	DELETEOBJECT(m_pImageOppStatUI);
}
