#include "framework.h"
#include "CPlayer.h"

#include "CIdle.h"
#include "CWalk.h"
#include "CRun.h"

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
	m_mapState[m_curState]->Exit();
	m_curState = state;
	m_mapState[m_curState]->Enter();
}

void CPlayer::ChangeDir(PlayerDir dir)
{
	m_curDir = dir;
}

void CPlayer::Init()
{
	m_mapState.insert(make_pair(PlayerState::Idle, new CIdle(this)));
	m_mapState.insert(make_pair(PlayerState::Walk, new CWalk(this)));
	m_mapState.insert(make_pair(PlayerState::Run, new CRun(this)));

	m_pAnimator = new CAnimator;

	m_mapState[PlayerState::Idle]->Init();
	m_mapState[PlayerState::Walk]->Init();
	m_mapState[PlayerState::Run]->Init();

	AddComponent(m_pAnimator);
	AddCollider(ColliderType::Rect, Vector(50, 40), Vector(0, 20));
}

void CPlayer::Update()
{
	if (GAME->GetCanMove())
	{
		m_mapState[m_curState]->Update();
	}
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
