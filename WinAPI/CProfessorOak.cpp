#include "framework.h"
#include "CProfessorOak.h"

CProfessorOak::CProfessorOak()
{
	m_pCallBack = nullptr;
	m_layer		= Layer::NPC;
	m_vecScale	= Vector(64, 80);
}

CProfessorOak::~CProfessorOak()
{
}

void CProfessorOak::SetCallBack(CallBackFunc callBackFunc)
{
	m_pCallBack = callBackFunc;
}

void CProfessorOak::Init()
{
	m_pImage = RESOURCE->LoadImg(L"ProfessorOak", L"Image\\NPC\\ProfessorOak.png");

	AddCollider(ColliderType::Rect, Vector(120, 120), Vector(0, 20));
}

void CProfessorOak::Update()
{
}

void CProfessorOak::Render()
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

void CProfessorOak::Release()
{
}

void CProfessorOak::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CProfessorOak::OnCollisionStay(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"�÷��̾�")
	{
		if (BUTTONDOWN(VK_SPACE))
		{
			if (m_pCallBack != nullptr)
				m_pCallBack();
		}
	}
}

void CProfessorOak::OnCollisionExit(CCollider* pOtherCollider)
{
}
