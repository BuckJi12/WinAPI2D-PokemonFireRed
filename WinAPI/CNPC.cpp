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

void CNPC::SetCallBack(CallBackFunc callBackFunc, DWORD_PTR param)
{
	m_pCallBack = callBackFunc;
	m_pParam = param;
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
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
		if (BUTTONDOWN(VK_SPACE))
		{
			if (m_pCallBack != nullptr)
				m_pCallBack(m_pParam);
		}
	}
}

void CNPC::OnCollisionExit(CCollider* pOtherCollider)
{
}
