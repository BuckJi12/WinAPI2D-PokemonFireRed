#include "framework.h"
#include "CTitleAnimation.h"

CTitleAnimation::CTitleAnimation()
{
	m_pAnimator = nullptr;
	m_pImage	= nullptr;
}

CTitleAnimation::~CTitleAnimation()
{
}

void CTitleAnimation::Init()
{
	m_pImage = RESOURCE->LoadImg(L"CharizardTitle", L"Image\\UI\\CharizardTitle.png");
	
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"CharizardTitle", m_pImage, Vector(0, 0), Vector(300, 300), Vector(300.f, 0.f), 0.2, 8);
	AddComponent(m_pAnimator);
	m_pAnimator->Play(L"CharizardTitle");
}

void CTitleAnimation::Update()
{
}

void CTitleAnimation::Render()
{
}

void CTitleAnimation::Release()
{
}
