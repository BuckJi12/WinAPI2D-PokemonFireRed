#include "framework.h"
#include "CTitleText.h"

CTitleText::CTitleText()
{
	m_pAnimator = nullptr;
	m_pImage	= nullptr;
}

CTitleText::~CTitleText()
{
}

void CTitleText::Init()
{
	m_pImage = RESOURCE->LoadImg(L"Title",L"Image\\UI\\Title.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"titleAni", m_pImage, Vector(0, 0), Vector(512.f, 256.f), Vector(512.f, 0.f), 0.5, 6);
	AddComponent(m_pAnimator);
	m_pAnimator->Play(L"titleAni");
}

void CTitleText::Update()
{
}

void CTitleText::Render()
{
}

void CTitleText::Release()
{
	delete m_pAnimator;
}
