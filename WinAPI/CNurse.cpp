#include "framework.h"
#include "CNurse.h"

CNurse::CNurse()
{
	m_layer		= Layer::NPC;
	m_vecScale	= Vector(64, 80);
}

CNurse::~CNurse()
{
}

void CNurse::Init()
{
	m_pImage = RESOURCE->LoadImg(L"Nurse", L"Image\\NPC\\Nurse.png");

	AddCollider(ColliderType::Rect, Vector(80, 150), Vector(0, 80));
}

void CNurse::Update()
{
}

void CNurse::Render()
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

void CNurse::Release()
{
}

void CNurse::OnCollisionEnter(CCollider* pOtherCollider)
{
	CNPC::OnCollisionEnter(pOtherCollider);
}

void CNurse::OnCollisionStay(CCollider* pOtherCollider)
{
	CNPC::OnCollisionStay(pOtherCollider);
}

void CNurse::OnCollisionExit(CCollider* pOtherCollider)
{
	CNPC::OnCollisionExit(pOtherCollider);
}
