#include "framework.h"
#include "CRun.h"

CRun::CRun(CPlayer* player) : CState(player)
{
	m_pRunImage = nullptr;
	m_speed = 400;
}

CRun::~CRun()
{
}

void CRun::Init()
{
	m_pRunImage = RESOURCE->LoadImg(L"PlayerWalk", L"Image\\Player\\PlayerRun.png");

	pPlayer->GetAnimator()->CreateAnimation(L"RunDown", m_pRunImage, Vector(0, 0), Vector(64.f, 80.f), Vector(64.f, 0.f), 0.2, 4);
	pPlayer->GetAnimator()->CreateAnimation(L"RunUp", m_pRunImage, Vector(0, 80), Vector(64.f, 80.f), Vector(64.f, 0.f), 0.2, 4);
	pPlayer->GetAnimator()->CreateAnimation(L"RunLeft", m_pRunImage, Vector(0, 160), Vector(64.f, 80.f), Vector(64.f, 0.f), 0.2, 4);
	pPlayer->GetAnimator()->CreateAnimation(L"RunRight", m_pRunImage, Vector(0, 240), Vector(64.f, 80.f), Vector(64.f, 0.f), 0.2, 4);
}

void CRun::Enter()
{
}

void CRun::Update()
{
	if (BUTTONSTAY(VK_DOWN))
	{
		pPlayer->m_vecPos.y += m_speed * DT;
		pPlayer->GetAnimator()->Play(L"RunDown", false);

		pPlayer->ChangeDir(PlayerDir::Down);
	}

	else if (BUTTONSTAY(VK_UP))
	{
		pPlayer->m_vecPos.y -= m_speed * DT;
		pPlayer->GetAnimator()->Play(L"RunUp", false);

		pPlayer->ChangeDir(PlayerDir::Up);
	}

	else if (BUTTONSTAY(VK_LEFT))
	{
		pPlayer->m_vecPos.x -= m_speed * DT;
		pPlayer->GetAnimator()->Play(L"RunLeft", false);

		pPlayer->ChangeDir(PlayerDir::Left);
	}

	else if (BUTTONSTAY(VK_RIGHT))
	{
		pPlayer->m_vecPos.x += m_speed * DT;
		pPlayer->GetAnimator()->Play(L"RunRight", false);

		pPlayer->ChangeDir(PlayerDir::Right);
	}
	else
	{
		pPlayer->ChangeState(PlayerState::Idle);
	}

	if (BUTTONDOWN(VK_SHIFT))
	{
		pPlayer->ChangeState(PlayerState::Walk);
	}
}

void CRun::Exit()
{
}
