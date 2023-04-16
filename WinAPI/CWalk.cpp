#include "framework.h"
#include "CWalk.h"
#include "CGameObject.h"
#include "CPlayer.h"

CWalk::CWalk(CPlayer* player) : CState(player)
{
	m_pWalkImage = nullptr;
	m_speed = 200;
}

CWalk::~CWalk()
{
}

void CWalk::Init()
{
	m_pWalkImage = RESOURCE->LoadImg(L"PlayerWalk", L"Image\\Player||PlayerWalk.png");

	pPlayer->GetAnimator()->CreateAnimation(L"WalkDown", m_pWalkImage, Vector(0, 0), Vector(16.f, 20.f), Vector(20.f, 0.f), 0.5, 3);
	pPlayer->GetAnimator()->CreateAnimation(L"WalkUP", m_pWalkImage, Vector(0, 20), Vector(16.f, 20.f), Vector(20.f, 0.f), 0.5, 3);
	pPlayer->GetAnimator()->CreateAnimation(L"WalkLeft", m_pWalkImage, Vector(0, 40), Vector(16.f, 20.f), Vector(20.f, 0.f), 0.5, 3);
	pPlayer->GetAnimator()->CreateAnimation(L"WalkRight", m_pWalkImage, Vector(0, 60), Vector(16.f, 20.f), Vector(20.f, 0.f), 0.5, 3);
}

void CWalk::Enter()
{
}

void CWalk::Update()
{
	if (BUTTONDOWN(VK_SHIFT))
	{
		pPlayer->ChangeState(PlayerState::Run);
	}

	if (BUTTONSTAY(VK_DOWN))
	{
		pPlayer->m_vecPos.y += m_speed * DT;
		pPlayer->GetAnimator()->Play(L"WalkDown", false);

		pPlayer->ChangeDir(PlayerDir::Down);
	}

	else if (BUTTONSTAY(VK_UP))
	{
		pPlayer->m_vecPos.y -= m_speed * DT;
		pPlayer->GetAnimator()->Play(L"WalkUP", false);

		pPlayer->ChangeDir(PlayerDir::Up);
	}

	else if (BUTTONSTAY(VK_LEFT))
	{
		pPlayer->m_vecPos.x -= m_speed * DT;
		pPlayer->GetAnimator()->Play(L"WalkLeft", false);

		pPlayer->ChangeDir(PlayerDir::Left);
	}

	else if (BUTTONSTAY(VK_RIGHT))
	{
		pPlayer->m_vecPos.x += m_speed * DT;
		pPlayer->GetAnimator()->Play(L"WalkRight", false);

		pPlayer->ChangeDir(PlayerDir::Right);
	}
	else
	{
		pPlayer->ChangeState(PlayerState::Idle);
	}
}

void CWalk::Exit()
{
}
