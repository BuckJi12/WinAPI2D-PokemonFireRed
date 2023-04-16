#include "framework.h"
#include "CPlayer.h"

#include "WinAPI.h"
#include "CInputManager.h"
#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CEventManager.h"
#include "CResourceManager.h"
#include "CCollider.h"
#include "CImage.h"
#include "CAnimator.h"

#include "CMissile.h"

CPlayer::CPlayer()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Player;
	m_strName = L"플레이어";

	m_curState = PlayerState::Idle;
	m_curDir = PlayerDir::Down;
}

CPlayer::~CPlayer()
{
}

CAnimator* CPlayer::GetAnimator()
{
	return m_pAnimator;
}

PlayerDir CPlayer::GetDir()
{
	return m_curDir;
}

void CPlayer::ChangeState(PlayerState state)
{
	m_curState = state;
}

void CPlayer::ChangeDir(PlayerDir dir)
{
	m_curDir = dir;
}

void CPlayer::Init()
{
	m_pAnimator = new CAnimator;

	AddComponent(m_pAnimator);
	AddCollider(ColliderType::Rect, Vector(90, 90), Vector(0, 0));
}

void CPlayer::Update()
{

}

void CPlayer::Render()
{
}

void CPlayer::Release()
{
}

void CPlayer::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CPlayer::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CPlayer::OnCollisionExit(CCollider* pOtherCollider)
{
}
