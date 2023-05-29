#include "framework.h"
#include "CNPC.h"

CNPC::CNPC()
{
	m_pImage	= nullptr;
	m_pAnimator = nullptr;
}

CNPC::~CNPC()
{
}

CImage* CNPC::GetImage()
{
	return m_pImage;
}

CAnimator* CNPC::GetAnimator()
{
	return m_pAnimator;
}

void CNPC::Init()
{
}

void CNPC::Update()
{
}

void CNPC::Render()
{
}

void CNPC::Release()
{
}

void CNPC::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CNPC::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CNPC::OnCollisionExit(CCollider* pOtherCollider)
{
}
