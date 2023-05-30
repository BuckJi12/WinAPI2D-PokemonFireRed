#include "framework.h"
#include "CChoosePokemon.h"

CChoosePokemon::CChoosePokemon()
{
	m_layer = Layer::NPC;
	m_vecScale = Vector(0, 0);
}

CChoosePokemon::~CChoosePokemon()
{
}

void CChoosePokemon::Init()
{
	AddCollider(ColliderType::Rect, Vector(193, 110), Vector(0, 00));
}

void CChoosePokemon::Update()
{
}

void CChoosePokemon::Render()
{
}

void CChoosePokemon::Release()
{
}

void CChoosePokemon::OnCollisionEnter(CCollider* pOtherCollider)
{
	CNPC::OnCollisionEnter(pOtherCollider);
}

void CChoosePokemon::OnCollisionStay(CCollider* pOtherCollider)
{
	CNPC::OnCollisionStay(pOtherCollider);
}

void CChoosePokemon::OnCollisionExit(CCollider* pOtherCollider)
{
	CNPC::OnCollisionExit(pOtherCollider);
}
