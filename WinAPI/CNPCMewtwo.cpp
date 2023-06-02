#include "framework.h"
#include "CNPCMewtwo.h"

CNPCMewtwo::CNPCMewtwo()
{
	m_layer = Layer::NPC;
	m_vecScale = Vector(128, 128);
}

CNPCMewtwo::~CNPCMewtwo()
{
}

void CNPCMewtwo::Init()
{
	m_pImage = RESOURCE->LoadImg(L"NPCMewtwo", L"Image\\NPC\\Mewtwo.png");

	AddCollider(ColliderType::Rect, Vector(60, 120), Vector(0, 0));
}

void CNPCMewtwo::Update()
{
}

void CNPCMewtwo::Render()
{
	if (nullptr != m_pImage)
	{
		RENDER->Image(
			m_pImage,
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f
		);
	}
}

void CNPCMewtwo::Release()
{
}

void CNPCMewtwo::OnCollisionEnter(CCollider* pOtherCollider)
{
	CNPC::OnCollisionEnter(pOtherCollider);
}

void CNPCMewtwo::OnCollisionStay(CCollider* pOtherCollider)
{
	CNPC::OnCollisionStay(pOtherCollider);
}

void CNPCMewtwo::OnCollisionExit(CCollider* pOtherCollider)
{
	CNPC::OnCollisionExit(pOtherCollider);
}
