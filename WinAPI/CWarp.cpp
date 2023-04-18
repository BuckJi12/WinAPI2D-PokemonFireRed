#include "framework.h"
#include "CWarp.h"

CWarp::CWarp()
{
	m_destination = GroupScene::None;
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Environment;
	m_strName = L"워프";
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
	AddCollider(ColliderType::Rect, Vector(m_vecScale), Vector(0, 0));
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
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
		CHANGESCENE(m_destination);
	}
}

void CWarp::OnCollisionStay(CCollider* pOtherCollider)
{

}

void CWarp::OnCollisionExit(CCollider* pOtherCollider)
{
}
