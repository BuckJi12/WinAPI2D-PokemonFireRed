#include "framework.h"
#include "CIdle.h"

CIdle::CIdle(CPlayer* player) : CState(player)
{
	m_pIdleImage = nullptr;
}

CIdle::~CIdle()
{
}

void CIdle::Init()
{
	m_pIdleImage = RESOURCE->LoadImg(L"PlayerIdle", L"Image\\Player||PlayerMove.png");

	pPlayer->GetAnimator()->CreateAnimation(L"IdleDown", m_pIdleImage, Vector(0, 0), Vector(16.f, 20.f), Vector(16.f, 0.f), 0.1, 1);
	pPlayer->GetAnimator()->CreateAnimation(L"IdleUP", m_pIdleImage, Vector(0, 20), Vector(16.f, 20.f), Vector(16.f, 0.f), 0.1, 1);
	pPlayer->GetAnimator()->CreateAnimation(L"IdleLeft", m_pIdleImage, Vector(0, 40), Vector(16.f, 20.f), Vector(16.f, 0.f), 0.1, 1);
	pPlayer->GetAnimator()->CreateAnimation(L"IdleRight", m_pIdleImage, Vector(0, 60), Vector(16.f, 20.f), Vector(16.f, 0.f), 0.1, 1);
}

void CIdle::Enter()
{
}

void CIdle::Update()
{
	if (BUTTONDOWN(VK_SHIFT))
	{
		pPlayer->ChangeState(PlayerState::Run);
	}

	if (BUTTONSTAY(VK_DOWN))
	{
		pPlayer->ChangeState(PlayerState::Walk);
	}

	else if (BUTTONSTAY(VK_UP))
	{
		pPlayer->ChangeState(PlayerState::Walk);
	}

	else if (BUTTONSTAY(VK_LEFT))
	{
		pPlayer->ChangeState(PlayerState::Walk);
	}

	else if (BUTTONSTAY(VK_RIGHT))
	{
		pPlayer->ChangeState(PlayerState::Walk);
	}
	else
	{
		switch (pPlayer->GetDir())
		{
		case PlayerDir::Down:
			pPlayer->GetAnimator()->Play(L"IdleDown", false);
			break;
		case PlayerDir::Up:
			pPlayer->GetAnimator()->Play(L"IdleUp", false);
			break;
		case PlayerDir::Left:
			pPlayer->GetAnimator()->Play(L"IdleLeft", false);
			break;
		case PlayerDir::Right:
			pPlayer->GetAnimator()->Play(L"IdleRight", false);
			break;
		default:
			break;
		}
	}
}

void CIdle::Exit()
{
}
