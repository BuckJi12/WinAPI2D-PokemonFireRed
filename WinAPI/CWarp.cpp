#include "framework.h"
#include "CWarp.h"

CWarp::CWarp()
{
	m_destination = GroupScene::None;
}

CWarp::~CWarp()
{
}

void CWarp::SetDestination(GroupScene destination)
{
	m_destination = destination;
}

void CWarp::Init()
{
}

void CWarp::Update()
{
}

void CWarp::Render()
{
}

void CWarp::Release()
{
}

void CWarp::OnCollisionEnter(CCollider* pOtherCollider)
{
	CHANGESCENE(m_destination);
}

void CWarp::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CWarp::OnCollisionExit(CCollider* pOtherCollider)
{
}
